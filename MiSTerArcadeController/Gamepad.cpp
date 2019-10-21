//
// Gamepad.cpp
//
// Author:
//       Mikael Norrgård <mick@daemonbite.com>
//
// Copyright (c) 2019 Mikael Norrgård <http://daemonbite.com>
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#include "Gamepad.h"

static const uint8_t _hidReportDescriptor[] PROGMEM = {
  0x05, 0x01,                       // USAGE_PAGE (Generic Desktop)
    0x09, 0x04,                       // USAGE (Joystick) (Maybe change to gamepad? I don't think so but...)
    0xa1, 0x01,                       // COLLECTION (Application)
    0x85, 0x01,                       // REPORT_ID (1) // change to 3 if using mouse and keyboard on 1&2
    0xa1, 0x00,                       // COLLECTION (Physical)
    
      0x05, 0x09,                       // USAGE_PAGE (Button)
      0x19, 0x01,                       // USAGE_MINIMUM (Button 1)
      0x29, 0x0C,                       // USAGE_MAXIMUM (Button 12)
      0x15, 0x00,                       // LOGICAL_MINIMUM (0)
      0x25, 0x01,                       // LOGICAL_MAXIMUM (1)
      0x95, 0x0C,                       // REPORT_COUNT (12)
      0x75, 0x01,                       // REPORT_SIZE (1)
      0x81, 0x02,                       // INPUT (Data,Var,Abs)

      0x95, 0x01,                       // REPORT_COUNT (1) ; pad out the bits into a number divisible by 8
      0x75, 0x04,                       // REPORT_SIZE (4)
      0x81, 0x03,                       // INPUT (Const,Var,Abs)
    
      0x05, 0x01,                       // USAGE_PAGE (Generic Desktop)
      0x09, 0x01,                       // USAGE (pointer)
      0xa1, 0x00,                       // COLLECTION (Physical) 
        0x09, 0x30,                       // USAGE (X)
        0x09, 0x31,                       // USAGE (Y)
        0x15, 0xff,                       // LOGICAL_MINIMUM (-1)
        0x25, 0x01,                       // LOGICAL_MAXIMUM (1)
        0x95, 0x02,                       // REPORT_COUNT (2)
        0x75, 0x08,                       // REPORT_SIZE (8)
        0x81, 0x02,                       // INPUT (Data,Var,Abs)
      0xc0,                             // END_COLLECTION

    0xc0,                             // END_COLLECTION
  0xc0,                             // END_COLLECTION 
};


Gamepad_::Gamepad_(void) 
{ 
  reportId=1;
  static HIDSubDescriptor node(_hidReportDescriptor, sizeof(_hidReportDescriptor));
  HID().AppendDescriptor(&node);
}

void Gamepad_::begin(uint8_t id) 
{
  reportId=id;
}

void Gamepad_::end(void) 
{
  this->reset();
}

void Gamepad_::reset()
{
  _GamepadReport.X = 0;
  _GamepadReport.Y = 0;
  _GamepadReport.buttons = 0;
  this->send();
}

void Gamepad_::send() 
{
  HID().SendReport(reportId,&_GamepadReport,sizeof(GamepadReport));
}
