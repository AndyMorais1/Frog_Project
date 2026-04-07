#include "button.h"

Button::Button(uint8_t pin, unsigned long debounceDelay)
{
    _pin = pin;
    _debounceDelay = debounceDelay;
    _lastState = HIGH; // Como usamos PULLUP, o estado padrão é HIGH
    _lastDebounceTime = 0;
    _pressed = false;
}

void Button::begin()
{
    // Configura o pino como entrada com o resistor interno de Pull-up do ESP32
    // Conexão física: Pino <-> Botão <-> GND
    pinMode(_pin, INPUT_PULLUP);
}

void Button::update()
{
    // Leitura instantânea do pino
    bool reading = digitalRead(_pin);

    // Se o estado mudou (devido a ruído ou clique)
    if (reading != _lastState)
    {
        _lastDebounceTime = millis();
    }

    // Se passou tempo suficiente desde a última mudança, a leitura é estável
    if ((millis() - _lastDebounceTime) > _debounceDelay)
    {
        // Se o estado estabilizou em LOW e antes estava em HIGH, houve um clique
        if (reading == LOW && _lastState == HIGH)
        {
            _pressed = true;
        }
    }

    _lastState = reading;
}

bool Button::wasPressed()
{
    if (_pressed)
    {
        _pressed = false; // "Consome" o evento de clique
        return true;
    }
    return false;
}

bool Button::isDown()
{
    return digitalRead(_pin) == LOW;
}