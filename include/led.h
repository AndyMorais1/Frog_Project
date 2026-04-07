#ifndef LED_H
#define LED_H

#include <FastLED.h>
#include <Arduino.h>
#include "config.h" // Para acessar NUM_LEDS, LED_PIN, etc.

class Led
{
private:
    CRGB _leds[NUM_LEDS]; // Array que representa as suas 3 LEDs
public:
    Led();
    void begin();
    void setColor(uint8_t r, uint8_t g, uint8_t b);
    void off();
};
#endif // LED_H