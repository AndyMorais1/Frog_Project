#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <Arduino.h>
#include "config.h"
#include "audio.h"
#include "led.h"
#include "motor.h"
#include "button.h"

class Controller
{
private:
    // Instâncias dos componentes
    Audio _audio;
    Led _led;
    Motor _motor;
    Button _btnNext;
    Button _btnRestart;

    // Variáveis
    int _currentPhase;
    unsigned long _lastAudioTime;
    const unsigned long AUDIO_REPEAT_INTERVAL = 15000; // 15 segundos

    // Funções Auxiliares
    void _nextPhase();         // Gerencia o incremento da fase
    void _resetSystem();       // Volta para a fase 0 e reseta hardware
    void _applyPhaseChanges(); // Aplica Áudio, LED e Motor para a fase atual

public:
    Controller();
    void begin();
    void update();
};

#endif