#ifndef __PCF8574_H
#define __PCF8574_H
#include <Arduino.h>
#include <Wire.h>

enum IO_PORT : uint8_t
{
    BIT_0 = 1 << 0,
    BIT_1 = 1 << 1,
    BIT_2 = 1 << 2,
    BIT_3 = 1 << 3,
    BIT_4 = 1 << 4,
    BIT_5 = 1 << 5,
    BIT_6 = 1 << 6,
    BIT_7 = 1 << 7
};

class PCF8574
{
public:
    static void setRegister(uint8_t);
    static uint8_t getRegister();
    static void setBit(uint8_t, bool);
    static bool getBit(uint8_t);
};

#endif