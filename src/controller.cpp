#include "controller.h"

Controller::Controller() : 
    _audio(&Serial2, DFPLAYER_RX_PIN, DFPLAYER_TX_PIN),
    _led(),
    _motor(MOTOR_PIN_1, MOTOR_PIN_2, MOTOR_PIN_3, MOTOR_PIN_4),
    _btnNext(BTN_NEXT_PIN),
    _btnRestart(BTN_RESTART_PIN),
    _currentPhase(0),
    _lastAudioTime(0)
{}

void Controller::begin() {
    Serial.begin(115200);
    _audio.begin();
    _led.begin();
    _motor.begin();
    _btnNext.begin();
    _btnRestart.begin();

    _applyPhaseChanges(); // Inicia Fase 0 (Intro + Descida)
}

void Controller::update() {
    _btnNext.update();
    _btnRestart.update();
    _motor.update();

    // 1. Lógica de Avanço (Bloqueada se o motor estiver a mover)
    if (_btnNext.wasPressed()) {
        if (!_motor.isMoving()) {
            _nextPhase();
        } else {
            Serial.println("Aguarde o Sapo chegar na posição!");
        }
    }

    // 2. Lógica de Restart (Sempre disponível)
    if (_btnRestart.wasPressed()) {
        _resetSystem();
    }

    // 3. Lógica de Repetição Automática (15 segundos)
    if (millis() - _lastAudioTime >= 15000) {
        if (!_motor.isMoving()) { // Não interrompe o movimento com áudio
            Serial.println("Repetindo áudio de orientação...");
            _audio.play(_currentPhase + 1);
            _lastAudioTime = millis(); // Reseta o cronômetro
        }
    }
}

void Controller::_nextPhase() {
    if (_currentPhase < (TOTAL_PHASES - 1)) {
        _currentPhase++;
        _applyPhaseChanges();
    }
}

void Controller::_resetSystem() {
    _currentPhase = 0;
    _applyPhaseChanges();
    Serial.println("Reiniciando para a Base...");
}

void Controller::_applyPhaseChanges() {
    // Sincroniza Áudio e Motor
    _audio.play(_currentPhase + 1);
    _motor.goToPhase(_currentPhase);
    
    // Reseta cronômetro para os próximos 15s começarem agora
    _lastAudioTime = millis(); 

    // Sincroniza LEDs
    switch (_currentPhase) {
        case 0: _led.setColor(255, 255, 255); break; // Intro
        case 1: _led.setColor(0, 0, 255);     break; // Molhar
        case 2: _led.setColor(255, 0, 255);   break; // Sabão
        case 3: _led.setColor(255, 255, 0);   break; // Esfregar
        case 4: _led.setColor(0, 255, 255);   break; // Enxaguar
        case 5: _led.setColor(255, 165, 0);   break; // Secar
        case 6: _led.setColor(0, 255, 0);     break; // Conclusão
    }
    Serial.printf("Fase Atual: %d | Cor Aplicada\n", _currentPhase);
}