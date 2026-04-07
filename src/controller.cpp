#include "controller.h"

Controller::Controller() : _audio(&Serial2, DFPLAYER_RX_PIN, DFPLAYER_TX_PIN),
                           _led(),
                           _motor(MOTOR_PIN_1, MOTOR_PIN_2, MOTOR_PIN_3, MOTOR_PIN_4),
                           _btnNext(BTN_NEXT_PIN),
                           _btnRestart(BTN_RESTART_PIN),
                           _currentPhase(0)
{
}

void Controller::begin()
{
    Serial.begin(115200);
    _audio.begin();
    _led.begin();
    _motor.begin();
    _btnNext.begin();
    _btnRestart.begin();
    // Inicia na fase Intro
    _applyPhaseChanges();
}

void Controller::update()
{
    _btnNext.update();
    _btnRestart.update();
    _motor.update();

    // Verifica cliques e chama as funções privadas
    if (_btnNext.wasPressed())
    {
        _nextPhase();
    }

    if (_btnRestart.wasPressed())
    {
        _resetSystem();
    }
}

// --- MÉTODOS PRIVADOS ---

void Controller::_nextPhase()
{
    if (_currentPhase < (TOTAL_PHASES - 1))
    {
        _currentPhase++;
        _applyPhaseChanges();
    }
}

void Controller::_resetSystem()
{
    _currentPhase = 0;
    _applyPhaseChanges();
    Serial.println("Sistema Reiniciado!");
}

void Controller::_applyPhaseChanges()
{
    // 1. Áudio (Pasta 01, arquivos 001.mp3, 002.mp3...)
    _audio.play(_currentPhase + 1);

    // 2. Motor (Calcula passos com base no config.h)
    _motor.goToPhase(_currentPhase);

    // 3. LEDs (Cores para cada uma das 7 fases)
    switch (_currentPhase)
    {
    case 0:
        _led.setColor(255, 255, 255);
        break; // Intro: Branco
    case 1:
        _led.setColor(0, 0, 255);
        break; // Molhar: Azul
    case 2:
        _led.setColor(255, 0, 255);
        break; // Sabão: Rosa
    case 3:
        _led.setColor(255, 255, 0);
        break; // Esfregar: Amarelo
    case 4:
        _led.setColor(0, 255, 255);
        break; // Enxaguar: Ciano
    case 5:
        _led.setColor(255, 165, 0);
        break; // Secar: Laranja
    case 6:
        _led.setColor(0, 255, 0);
        break; // Conclusão: Verde
    }

    Serial.printf("Fase Atual: %d\n", _currentPhase);
}