#ifndef __PCF8574_H
#define __PCF8574_H
#include <Arduino.h>
#include <Wire.h>

enum IO_PORT : uint8_t
{
    POMP = 1 << 0,
    VLV_1 = 1 << 1,
    VLV_2 = 1 << 2,
    VLV_3 = 1 << 3,
    VLV_4 = 1 << 4,
    VLV_5 = 1 << 5,
    VLV_6 = 1 << 6,
    VLV_7 = 1 << 7
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