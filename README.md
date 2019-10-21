# MiSTer-Arcade-Controller
This is an arcade controller project for the MiSTer and any other device accepting USB HID joysticks using an Arduino Pro Micro. The input lag for the Arduino configured as a joystick/gamepad is low, lower than the "Zero Delay" USB encoders.

## Wiring
The wiring is simple. Connect one leg of each microswitch to GND and the other leg to the digital pin according to the schematic below. That's it!  
![Assemble1](images/mister-arcade-controller-wiring.png)

## Configuring the Arduino
Just download the free Arduino IDE, connect the Arduino Pro Micro to a USB port and let the drivers install, then upload the project in the IDE.
