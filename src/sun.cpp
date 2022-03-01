#include <sun.h>

extern DS3231 rtc;

void Sun::lighting()
{

    bool day;
    uint8_t bright;
    if ((rtc.getHour() >= EEPROM.read(EE_SUNRISE_HOUR)) && (rtc.getHour() < EEPROM.read(EE_SUNSET_HOUR)))
    {
        day = true;
        elapsedSeconds riseInt;
        if (riseInt >= (EEPROM.read(EE_DURATION_SUN) * 60))
            bright = 255;
    }
    else
    {
        day = false;
        bright = 0;
    }

    if ((EEPROM.read(EE_SUNRISE_HOUR) == rtc.getHour()) && (EEPROM.read(EE_SUNRISE_MINUTE) >= rtc.getMinute()) && (EEPROM.read(EE_DURATION_SUN) != 0) && (day == true))
    {
        if (bright == 255)
            return;
        elapsedSeconds brightInt;
        if (brightInt >= (EEPROM.read(EE_DURATION_SUN) * 60 / 256))
        {
            brightInt = 0;
            bright++;
            analogWrite(LIGHT, bright);
        }
    }
    if ((EEPROM.read(EE_SUNSET_HOUR) == rtc.getHour()) && (EEPROM.read(EE_SUNSET_MINUTE) >= rtc.getMinute()) && (EEPROM.read(EE_DURATION_SUN) != 0) && (day == false))
    {
        if (bright == 0)
            return;
        elapsedSeconds brightInt;
        if (brightInt >= (EEPROM.read(EE_DURATION_SUN) * 60 / 256))
        {
            brightInt = 0;
            bright--;
            analogWrite(LIGHT, bright);
        }
    }
}
