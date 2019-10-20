#include "gamepad.h"

// Set up USB HID gamepad
Gamepad_ Gamepad;
bool usbUpdate = false; // Should gamepad data be sent to USB?

uint8_t axes = 0x0f;
uint8_t axesPrev = 0x0f;
uint8_t buttons = 0;
uint8_t buttonsPrev = 0;

void setup() 
{
  // Axes
  DDRF  &= ~B11110000; // Set A0-A3 as inputs
  PORTF |=  B11110000; // Enable internal pull-up resistors

  // Buttons
  DDRD  &= ~B00000011; // Set PD0-PD1 as inputs
  PORTD |=  B00000011; // Enable internal pull-up resistors
  DDRB  &= ~B01111110; // Set PB1-PB6 as inputs
  PORTB |=  B01111110; // Enable internal pull-up resistors

  Gamepad.begin(1);
}

void loop() 
{
  // Read axis and button inputs (bitwise NOT results in a 1 when button/axis pressed)
  axes = ~(PINF & B11110000);
  buttons = ~((PIND & B00000011) | ((PINB & B01111110) << 1));

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
