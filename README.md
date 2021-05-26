# DaemonBite-Arcade-Encoder
This is an arcade controller project for the MiSTer FPGA project and any other device accepting USB HID joysticks using an Arduino Pro Micro. This project can also be used to create a NeoGeo/Atari/Commodore/Amiga controller to USB adapters.

This project is an open source "lite" version of an arcade encoder I sell in my shop. If you want to support my work I sell the fully featured ones at https://daemonbite.com.

The input lag for an arcade controller or adapter built around this project is minimal. Here is the result from a test with a 1ms polling rate on a MiSTer with this project:

| Samples | Average | Max | Min | Std Dev |
| ------ | ------ | ------ | ------ | ------ | 
| 13962 | 0.74ms | 1.28ms | 0.23ms | 0.29ms |

## Wiring (Arcade Controller)
The wiring is simple. Connect one leg of each microswitch to GND and the other leg to the digital pin according to the schematic below. That's it!  
![Assemble1](images/daemonbite-arcade-encoder-wiring.png)

## Recommended layout (for PS3 stick compatibility)
Blue text in image (silk screen) corresponds to the Bx button numbers in the image for wiring above. 
![Assemble2](images/daemonbite-arcade-encoder-layout.png)

## Wiring (NeoGeo USB Adapter)
![Assemble3](images/daemonbite-arcade-encoder-wiring-neogeo.png)

## Wiring (Atari/Commodore/Amiga USB Adapter)
![Assemble4](images/daemonbite-arcade-encoder-wiring-atari.png)

## Programming the Arduino
1. Download the free Arduino IDE: https://www.arduino.cc/en/main/software
2. Connect the Arduino Pro Micro to a USB port and let the drivers install.
3. Choose the correct board and virtual COM port in the IDE.
3. Compile/Upload the project.

## License
This project is licensed under the GNU General Public License v3.0. The name "daemonbite" is registered to my company in Finland and should not be used by others.
