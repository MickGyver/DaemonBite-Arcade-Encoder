/*  DaemonBite Arcade Encoder
 *  Author: Mikael Norrgård <mick@daemonbite.com>
 *
 *  Copyright (c) 2020 Mikael Norrgård <http://daemonbite.com>
 *  
 *  GNU GENERAL PUBLIC LICENSE
 *  Version 3, 29 June 2007
 *  
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *  
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *  
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *  
 */

#include "gamepad.h"

// Set up USB HID gamepad
Gamepad_ Gamepad;
bool usbUpdate = false; // Should gamepad data be sent to USB?

uint8_t axes = 0x0f;
uint8_t axesPrev = 0x0f;
uint16_t buttons = 0;
uint16_t buttonsPrev = 0;

void setup() 
{
  // Axes
  DDRF  &= ~B11110000; // Set A0-A3 as inputs
  PORTF |=  B11110000; // Enable internal pull-up resistors

  // Buttons
  DDRD  &= ~B10011111; // Set PD0-PD4 and PD7 as inputs
  PORTD |=  B10011111; // Enable internal pull-up resistors
  DDRB  &= ~B01111110; // Set PB1-PB6 as inputs
  PORTB |=  B01111110; // Enable internal pull-up resistors

  Gamepad.begin(1);
}

void loop() 
{
  // Read axis and button inputs (bitwise NOT results in a 1 when button/axis pressed)
  axes = ~(PINF & B11110000);
  buttons = ~((PIND & B00011111) | ((PIND & B10000000) << 4) | ((PINB & B01111110) << 4));

  // Has axis inputs changed?
  if(axes != axesPrev)
  {
    Gamepad._GamepadReport.Y = ((axes & B01000000)>>6) - ((axes & B10000000)>>7);
    Gamepad._GamepadReport.X = ((axes & B00010000)>>4) - ((axes & B00100000)>>5);
    axesPrev = axes;
    usbUpdate = true;
  }

  // Has button inputs changed?
  if(buttons != buttonsPrev)
  {
    Gamepad._GamepadReport.buttons = buttons;
    buttonsPrev = buttons;
    usbUpdate = true;
  }

  // Should gamepad data be sent to USB?
  if(usbUpdate)
  {
    Gamepad.send();
    usbUpdate = false;
  }

}
