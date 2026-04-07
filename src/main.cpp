#include <Arduino.h>
#include "controller.h"

Controller _controller;

void setup()
{
  _controller.begin();
}

void loop()
{
  _controller.update();
}