#include <sun.h>

extern DS3231 rtc;
uint8_t SunriseHour = EEPROM.read(0);
uint8_t SunriseMinute = EEPROM.read(1);
uint8_t duratRise = EEPROM.read(2);
uint8_t SunsetHour = EEPROM.read(3);
uint8_t SunsetMinute = EEPROM.read(4);
uint8_t duratSet = EEPROM.read(5);

void Sun::sunrise()
{
    elapsedSeconds eSeconds;
    uint8_t bright = 0;
    if ((SunriseHour == rtc.getHour()) && (SunriseMinute >= rtc.getMinute()) && (duratRise != 0))
    {
        if (bright = 255)
            return;
        if (eSeconds >= (duratRise * 60 / 256))
        {
            eSeconds = 0;
            bright++;
            analogWrite(LIGHT, bright);
        }
    }
}
void Sun::sunset()
{
    elapsedSeconds eSeconds;
    uint8_t bright=255;
    if ((SunsetHour == rtc.getHour()) && (SunsetMinute >= rtc.getMinute()) && (duratSet != 0))
        for (uint8_t bright = 255; bright > 0;)
        {
            if (bright = 0)
                return;
            if (eSeconds >= (duratSet*60/256))
            {
                eSeconds = 0;
                bright--;
                analogWrite(LIGHT, bright);
            }
        }
}
void Sun::day()
{
    elapsedSeconds eSeconds;
    if ((rtc.getHour() >= (SunriseHour)) && (rtc.getHour() < SunsetHour) && (eSeconds >= (duratRise * 60)))
        digitalWrite(LIGHT, HIGH);
}
void Sun::night()
{
    elapsedSeconds eSeconds;
    if ((rtc.getHour() >= (SunsetHour)) && (rtc.getHour() < SunriseHour) && (eSeconds >= (duratSet * 60)))
        digitalWrite(LIGHT, LOW);
}