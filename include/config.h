#ifndef CONFIG_H
#define CONFIG_H

#include <Arduino.h>

// =============================================================================
// DFPLAYER MINI (Serial2)
// Nota: Conecte o TX do DFPlayer no RX do ESP32 e vice-versa. 
// Use um resistor de 1k ohms na linha RX do DFPlayer para reduzir ruído.
// =============================================================================
#define DFPLAYER_RX_PIN 16  // Conecta no TX do DFPlayer
#define DFPLAYER_TX_PIN 17  // Conecta no RX do DFPlayer (com resistor 1k)

// =============================================================================
// STEPPER MOTOR (28BYJ-48 com Driver ULN2003)
// Sequência padrão para bibliotecas como a AccelStepper ou Stepper.h
// =============================================================================
#define STEPPER_PIN_1 26
#define STEPPER_PIN_2 25
#define STEPPER_PIN_3 33
#define STEPPER_PIN_4 32

// =============================================================================
// LEDS RGB (WS2812B / Neopixel)
// =============================================================================
#define LED_DATA_PIN 13
#define NUM_LEDS     12     // Altere para a quantidade que estiver usando

// =============================================================================
// BOTÕES (Input Pull-up)
// Conexão: Pino <-> Botão <-> GND
// =============================================================================
#define BUTTON_A_PIN 14
#define BUTTON_B_PIN 27

#endif // CONFIG_H