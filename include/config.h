#ifndef CONFIG_H
#define CONFIG_H

#include <Arduino.h>

// --- DFPLAYER ---
#define DFPLAYER_RX_PIN 16
#define DFPLAYER_TX_PIN 17
#define DFPLAYER_BUSY_PIN 19

// --- MOTOR STEPPER ---
#define MOTOR_PIN_1 32 // Ordem corrigida conforme seu teste físico
#define MOTOR_PIN_2 25
#define MOTOR_PIN_3 33
#define MOTOR_PIN_4 26

// --- LEDS WS2812 ---
#define LED_DATA_PIN 13
#define NUM_LEDS 12

// --- BOTÕES ---
#define BTN_NEXT_PIN 14
#define BTN_RESTART_PIN 27

// --- LÓGICA MECÂNICA ---
#define TOTAL_PHASES 7
#define MAX_STEPS 5500

#endif