#ifndef BUTTON_H
#define BUTTON_H

#include <Arduino.h>

class Button
{
private:
    uint8_t _pin;
    bool _lastState;
    unsigned long _lastDebounceTime;
    unsigned long _debounceDelay;
    bool _pressed;

public:
    // Construtor: recebe o pino e define o tempo de debounce (50ms padrão)
    Button(uint8_t pin, unsigned long debounceDelay = 50);

    void begin();

    // Atualiza o estado do botão (deve ser chamado no loop ou no update da controller)
    void update();

    // Retorna true apenas uma vez quando o botão é pressionado
    bool wasPressed();

    // Retorna o estado atual (true se estiver pressionado agora)
    bool isDown();
};

#endif