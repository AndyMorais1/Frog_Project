#include "motor.h"

Motor::Motor(uint8_t p1, uint8_t p2, uint8_t p3, uint8_t p4)
    : _stepper(AccelStepper::HALF4WIRE, p1, p3, p2, p4)
{
    // Nota: A ordem p1, p3, p2, p4 é um "truque" da biblioteca AccelStepper
    // para que o motor 28BYJ-48 funcione corretamente no modo Half-Step.
    _stepsPerPhase = 1000; // Ajuste este valor após testar a altura do seu fio
}

void Motor::begin()
{
    _stepper.setMaxSpeed(1000.0);    // Velocidade máxima (passos por segundo)
    _stepper.setAcceleration(500.0); // Aceleração suave
}

void Motor::goToPhase(int phase)
{
    // Calcula a posição destino: Fase 0 = 0 passos, Fase 1 = 1000 passos, etc.
    long targetPos = phase * _stepsPerPhase;
    _stepper.moveTo(targetPos);
}

void Motor::resetPosition()
{
    _stepper.moveTo(0);
}

void Motor::update()
{
    // Esta função precisa ser chamada constantemente para o motor se mover
    _stepper.run();
}

bool Motor::isMoving()
{
    return _stepper.distanceToGo() != 0;
}