#include <data.h>

extern DS3231 rtc;
extern MicroDS18B20<DALLAS_1> ds;
extern EncButton<EB_TICK, 2, 3, 0> enc;

int8_t tempHeatNow;
int8_t tempAirOut;
int8_t tempAirIn;

void Heat::Heating()
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
        analogWrite(HEAT, EEPROM.read(EE_HEATING_PWM));
    if (tempHeatNow > (EEPROM.read(EE_TEMP_HEATING_DAY) + 1) && (esDH >= 60) && (day == true))
        analogWrite(HEAT, 0);
    if (tempHeatNow < (EEPROM.read(EE_TEMP_HEATING_NIGHT) - 1) && (esDH >= 60) && (day == false))
        analogWrite(HEAT, EEPROM.read(EE_HEATING_PWM));
    if (tempHeatNow > (EEPROM.read(EE_TEMP_HEATING_NIGHT) + 1) && (esDH >= 60) && (day == false))
        analogWrite(HEAT, 0);
}

void Heat::Cooling()
{

    elapsedSeconds es;
    if ((tempAirIn > EEPROM.read(EE_TEMP_COOLING_IN_ON)) && (tempAirOut > EEPROM.read(EE_TEMP_COOLING_OUT_ON)) && (es >= 300))
    {
        digitalWrite(DRV_SIG_1, HIGH);
        digitalWrite(DRV_SIG_2, LOW);
        analogWrite(DRV_PWM, EEPROM.read(EE_COOLING_PWM));
        elapsedSeconds drvStopDelay;
        if (drvStopDelay >= EEPROM.read(EE_COOLING_DRV_STOP_DELAY))
            analogWrite(DRV_PWM, 0);
    }

    if ((tempAirIn < EEPROM.read(EE_TEMP_COOLING_IN_OFF)) && (tempAirOut < EEPROM.read(EE_TEMP_COOLING_OUT_OFF)) && (es >= 300))
    {
        digitalWrite(DRV_SIG_1, LOW);
        digitalWrite(DRV_SIG_2, HIGH);
        analogWrite(DRV_PWM, EEPROM.read(EE_COOLING_PWM));
        elapsedSeconds drvStopDelay;
        if (drvStopDelay >= EEPROM.read(EE_COOLING_DRV_STOP_DELAY))
            analogWrite(DRV_PWM, 0);
    }
}
void Heat::ButCooling()
{

    digitalWrite(DRV_SIG_1, !digitalRead(DRV_SIG_1));
    digitalWrite(DRV_SIG_2, !digitalRead(DRV_SIG_2));
    analogWrite(DRV_PWM, EEPROM.read(EE_COOLING_PWM));
    elapsedSeconds drvStopDelay;
    if (drvStopDelay >= EEPROM.read(EE_COOLING_DRV_STOP_DELAY))
        analogWrite(DRV_PWM, 0);
}