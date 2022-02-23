#pragma once
#include <elapsedMillis.h>
#include <Arduino.h>
#include <data.h>

class Dimmer
{
private:
    uint8_t start;

public:
    elapsedMillis eSeconds;
    uint16_t interval;
    void rassvet();
    void zakat();
};
