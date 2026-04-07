#include "motor.h"

Motor::Motor(uint8_t p1, uint8_t p2, uint8_t p3, uint8_t p4) 
    : _stepper(AccelStepper::HALF4WIRE, p1, p2, p3, p4) {}

void Motor::begin() {
    _stepper.setMaxSpeed(900);   
    _stepper.setAcceleration(500); 

    // Homing: Assume que está no topo e desce para o zero
    _stepper.setCurrentPosition(MAX_STEPS);
    _stepper.moveTo(0);
}

void Motor::update() {
    _stepper.run();
}

void Motor::goToPhase(int phase) {
    long targetPos;
    if (phase <= 0) targetPos = 0;
    else if (phase >= 6) targetPos = MAX_STEPS;
    else targetPos = (MAX_STEPS / 6) * phase;

    _stepper.moveTo(targetPos);
}

bool Motor::isMoving() {
    return _stepper.distanceToGo() != 0;
}