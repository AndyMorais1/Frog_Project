#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "controller.h"
#include "config.h"
#include <Arduino.h>
#include "audio.h"
#include "led.h"
#include "motor.h"
#include "button.h"

class Controller
{
private:
    //
public:
    Controller();
    void begin();
    void update();
};

#endif