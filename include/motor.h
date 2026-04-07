#ifndef MOTOR_H
#define MOTOR_H

#include <Arduino.h>
#include <AccelStepper.h>
#include "config.h"

class Motor {
private:
    AccelStepper _stepper;
    const long POSICAO_BAIXO = 0;      
    const long POSICAO_CIMA = 5500;    // Valor total do seu estendal
    const int NUM_PARADAS = 6;         // Divisões do trajeto

public:
    Motor(uint8_t p1, uint8_t p2, uint8_t p3, uint8_t p4);
    void begin();
    void update();
    
    // Agora recebe o índice da fase (0 a 6) para calcular a altura
    void goToPhase(int phase);
    
    void resetToBottom();
    bool isMoving();
};

#endif // MOTOR_H