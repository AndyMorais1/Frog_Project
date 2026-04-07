#ifndef MOTOR_H
#define MOTOR_H

#include <Arduino.h>
#include <AccelStepper.h>
#include "config.h"

class Motor {
private:
    // 4 indica que usamos um driver de 4 fios (ULN2003)
    // A sequência 1, 3, 2, 4 é a correta para o 28BYJ-48 na AccelStepper
    AccelStepper _stepper;
    long _stepsPerPhase;

public:
    // Construtor que recebe os pinos definidos no config.h
    Motor(uint8_t p1, uint8_t p2, uint8_t p3, uint8_t p4);

    void begin();
    
    // Move para uma fase específica (0 a 6)
    void goToPhase(int phase);
    
    // Retorna o sapo para a posição inicial (0)
    void resetPosition();

    // Deve ser chamado no loop principal (ou no update da Controller)
    void update();

    // Verifica se o motor ainda está se movendo
    bool isMoving();
};

#endif