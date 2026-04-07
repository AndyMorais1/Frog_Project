#ifndef CONFIG_H
#define CONFIG_H

#include <Arduino.h>

// --- DFPLAYER (UART2) ---
#define DFPLAYER_RX_PIN   16 
#define DFPLAYER_TX_PIN   17 
#define DFPLAYER_BUSY_PIN 19 

// --- MOTOR STEPPER (28BYJ-48 + ULN2003) ---
#define MOTOR_PIN_1 26
#define MOTOR_PIN_2 25
#define MOTOR_PIN_3 33
#define MOTOR_PIN_4 32

// --- LEDS WS2812 ---
#define LED_DATA_PIN 13
#define NUM_LEDS     12 // Ajuste conforme seu anel/fita

// --- BOTÕES ---
#define BTN_NEXT_PIN   14
#define BTN_RESTART_PIN 27

// --- LÓGICA DO PROJETO ---
#define TOTAL_PHASES 7
#define STEPS_PER_PHASE 512 // Ajuste este valor conforme a distância física entre as fases no seu fio

#endif // CONFIG_H