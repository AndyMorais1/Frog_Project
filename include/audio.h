#ifndef AUDIO_H
#define AUDIO_H
#include <Arduino.h>
#include <DFRobotDFPlayerMini.h>

class Audio
{
private:
    DFRobotDFPlayerMini _player;
    HardwareSerial *_serial;
    uint8_t _rx, _tx;
    int _volume;

public:
    Audio(HardwareSerial *serial, uint8_t rx, uint8_t tx);
    void begin();
    void stop();
    void play(int trackNumber);
};

#endif // AUDIO_H