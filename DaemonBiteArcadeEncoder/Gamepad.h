//
// Gamepad.h
//
// Author:
//       Mikael Norrgård <mick@daemonbite.com>
//
// Copyright (c) 2019 Mikael Norrgård <http://daemonbite.com>
//
// GNU GENERAL PUBLIC LICENSE
// Version 3, 29 June 2007

#include "HID.h"

typedef struct {
  uint16_t buttons;
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
