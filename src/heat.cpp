#include <data.h>

extern DS3231 rtc;
extern MicroDS18B20<DALLAS_1> ds;

int8_t tempHeatNow;

void Heat::heating()
{

    bool day;
    if ((rtc.getHour() >= EEPROM.read(EE_SUNRISE_HOUR)) && (rtc.getHour() < EEPROM.read(EE_SUNSET_HOUR)))
        day = true;
    else
        day = false;
    elapsedMillis emds;
    elapsedSeconds esDH;
    ds.requestTemp();
    if (emds >= 1000)
        if (ds.readTemp())
            tempHeatNow = (int8_t(ds.getTemp()));
    if (tempHeatNow < (EEPROM.read(EE_TEMP_HEATING_DAY) - 1) && (esDH >= 60) && (day == true))
        analogWrite(HEAT, EEPROM.read(EE_TEMP_HEATING_POWER));
    if (tempHeatNow > (EEPROM.read(EE_TEMP_HEATING_DAY) + 1) && (esDH >= 60) && (day == true))
        analogWrite(HEAT, 0);
    if (tempHeatNow < (EEPROM.read(EE_TEMP_HEATING_NIGHT) - 1) && (esDH >= 60) && (day == false))
        analogWrite(HEAT, EEPROM.read(EE_TEMP_HEATING_POWER));
    if (tempHeatNow > (EEPROM.read(EE_TEMP_HEATING_NIGHT) + 1) && (esDH >= 60) && (day == false))
        analogWrite(HEAT, 0);
}
