#include <data.h>

extern DS3231 rtc;
extern MicroDS18B20<DALLAS_1> ds;
extern EncButton<EB_TICK, 2, 3, 0> enc;
extern AHT10 aht10;
int8_t tempHeatNow;
uint8_t tempIn;
uint8_t tempOut;
elapsedSeconds interVal;
elapsedMillis emds;
elapsedSeconds dsInt;

void Heat::Heating()
{
    if (dsInt >= 10)
    {
        dsInt = 0;
        bool day;
        if ((rtc.getHour() >= EEPROM.read(EE_SUNRISE_HOUR)) && (rtc.getHour() < EEPROM.read(EE_SUNSET_HOUR)))
            day = true;
        else
            day = false;

        ds.requestTemp();
        if (emds >= 1000)
            if (ds.readTemp())
                tempHeatNow = (int8_t(ds.getTemp()));
        if (tempHeatNow < EEPROM.read(EE_TEMP_HEATING_DAY) && (day == true))
            analogWrite(HEAT, EEPROM.read(EE_HEATING_PWM));
        if (tempHeatNow > EEPROM.read(EE_TEMP_HEATING_DAY) && (day == true))
            analogWrite(HEAT, 0);
        if (tempHeatNow < EEPROM.read(EE_TEMP_HEATING_NIGHT) && (day == false))
            analogWrite(HEAT, EEPROM.read(EE_HEATING_PWM));
        if (tempHeatNow > EEPROM.read(EE_TEMP_HEATING_NIGHT) && (day == false))
            analogWrite(HEAT, 0);
    }
}

void Heat::Cooling()
{

    elapsedSeconds drvStopDelay;
    uint8_t ds;
    if (interVal >= 30)
    {
        tempIn = int8_t(aht10.getTemperature());
        tempOut = int8_t(aht10.getTemperature());
        interVal = 0;

        if ((tempIn > EEPROM.read(EE_TEMP_COOLING_IN_OPEN)) && (tempOut > EEPROM.read(EE_TEMP_COOLING_OUT_OPEN)) && digitalRead(DRV_SIG_2))
        {
            digitalWrite(DRV_SIG_1, HIGH);
            digitalWrite(DRV_SIG_2, LOW);
            analogWrite(DRV_PWM, EEPROM.read(EE_COOLING_PWM));
            drvStopDelay = 0;
            ds = EEPROM.read(EE_COOLING_DRV_STOP_DELAY);
            while (1)
            {
                if (drvStopDelay >= ds)
                {
                    analogWrite(DRV_PWM, 0);
                    return;
                }
            }
        }

        if ((tempIn < EEPROM.read(EE_TEMP_COOLING_IN_CLOSE)) && (tempOut < EEPROM.read(EE_TEMP_COOLING_OUT_CLOSE)) && digitalRead(DRV_SIG_1))
        {
            digitalWrite(DRV_SIG_1, LOW);
            digitalWrite(DRV_SIG_2, HIGH);
            analogWrite(DRV_PWM, EEPROM.read(EE_COOLING_PWM));
            drvStopDelay = 0;
            ds = (EEPROM.read(EE_COOLING_DRV_STOP_DELAY) + 3);
            while (1)
            {
                if (drvStopDelay >= ds)
                {
                    analogWrite(DRV_PWM, 0);
                    return;
                }
            }
        }
    }
}

void Heat::ButCooling()
{

    elapsedSeconds drvStopDelay;
    uint8_t ds;
    digitalWrite(DRV_SIG_1, !digitalRead(DRV_SIG_1));
    digitalWrite(DRV_SIG_2, !digitalRead(DRV_SIG_2));
    (digitalRead(DRV_SIG_1)) ? ds = EEPROM.read(EE_COOLING_DRV_STOP_DELAY) : ds = (EEPROM.read(EE_COOLING_DRV_STOP_DELAY) + 3);
    analogWrite(DRV_PWM, EEPROM.read(EE_COOLING_PWM));
    while (1)
    {
        if (drvStopDelay >= ds)
        {
            analogWrite(DRV_PWM, 0);
            return;
        }
    }
}