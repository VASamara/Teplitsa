#include <PCF8574.h>

static const uint8_t PCF8574_ADDR = 0x20;
IO_PORT bit;

void PCF8574::setRegister(uint8_t setVal)
{
    Wire.beginTransmission(PCF8574_ADDR);
    Wire.write(PCF8574_ADDR);
    Wire.write(setVal);
    Wire.endTransmission();
}

uint8_t PCF8574::getRegister()
{
    Wire.beginTransmission(PCF8574_ADDR);
    Wire.requestFrom(PCF8574_ADDR, (uint8_t)1);
    uint8_t data = Wire.read();
    Wire.endTransmission();
    return data;
}

void PCF8574::setBit(IO_PORT bit, bool vol)
{
    Wire.beginTransmission(PCF8574_ADDR);
    Wire.requestFrom(PCF8574_ADDR, (uint8_t)1);
    uint8_t data = Wire.read();
    (vol == true) ? Wire.write(data | bit) : Wire.write(data & ~bit);
    Wire.endTransmission();
}

bool PCF8574::getBit(IO_PORT bit)
{
    Wire.beginTransmission(PCF8574_ADDR);
    Wire.requestFrom(PCF8574_ADDR, (uint8_t)1);
    uint8_t data = Wire.read();
    Wire.endTransmission();
    bool dt = data & bit;
    return dt;
}