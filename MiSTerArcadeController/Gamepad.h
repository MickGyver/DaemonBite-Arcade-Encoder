//
// Gamepad.h
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

#include "HID.h"

// The numbers after colon are bit fields, meaning how many bits the field uses.
// Remove those if there are problems
typedef struct {
  union 
  {
    struct {
      bool  b0: 1 ;
      bool  b1: 1 ;
      bool  b2: 1 ;
      bool  b3: 1 ;
      bool  b4: 1 ;
      bool  b5: 1 ;
      bool  b6: 1 ;
      bool  b7: 1 ; 
    };
    uint8_t buttons;
  };
  int8_t X  ;
  int8_t Y  ;  
  
} GamepadReport;


class Gamepad_
{  
  private:
    uint8_t reportId;
    
  public:
    GamepadReport _GamepadReport;
    Gamepad_(void);
    void begin(uint8_t id);
    void end(void);
    void reset(void);
    void send();
};
extern Gamepad_ Gamepad;
