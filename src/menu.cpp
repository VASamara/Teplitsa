#include <menu.h>
extern LiquidCrystal_I2C lcd;
extern AHT10 aht10;
extern DS3231 rtc;
extern uint8_t numValve;
extern EncButton<EB_TICK, 3, 2, 0> enc;
elapsedMillis t;

// uint8_t i = constrain(i, 0, 3);

void MenuLCD::SetupMenuSet()
{
    while (1)
    {
        enc.tick();
        lcd.blink();
        uint8_t str[]{8, 8, 8, 8};
        uint8_t sim[]{0, 1, 2, 3};
        uint8_t num[]{EE_COOLING_ON, EE_HEATING_ON, EE_WATERING_ON, EE_LOGGING_ON};
        uint8_t i = constrain(i, 0, 3);
        if (enc.right())
            i++;
        if (enc.left())
            i--;
        lcd.setCursor(str[i], sim[i]);

        if (enc.click())
        {
            if (EEPROM.read(num[i]) == 0)
            {
                EEPROM.put(num[i], 1);
                lcd.print("On ");
                lcd.noBlink();
                return;
            }
            if (EEPROM.read(num[i]) == 1)
            {
                EEPROM.put(num[i], 0);
                lcd.print("Off");
                lcd.noBlink();
                return;
            }
        }
    }
}

void MenuLCD::SetupMenu()
{

    lcd.setCursor(0, 0);
    lcd.print(F("Cooling             "));
    lcd.setCursor(0, 1);
    lcd.print(F("Heating             "));
    lcd.setCursor(0, 2);
    lcd.print(F("Poliv               "));
    lcd.setCursor(0, 3);
    lcd.print(F("Logging             "));
    lcd.setCursor(8, 0);
    (EEPROM.read(EE_COOLING_ON)) ? lcd.print("On ") : lcd.print("Off");
    lcd.setCursor(8, 1);
    (EEPROM.read(EE_HEATING_ON)) ? lcd.print("On ") : lcd.print("Off");
    lcd.setCursor(8, 2);
    (EEPROM.read(EE_WATERING_ON)) ? lcd.print("On ") : lcd.print("Off");
    lcd.setCursor(8, 3);
    (EEPROM.read(EE_LOGGING_ON)) ? lcd.print("On ") : lcd.print("Off");
}
void MenuLCD::MainMenu()
{
    lcd.setCursor(0, 0);
    lcd.print(F("  :  Day  AtD    mmR"));
    lcd.setCursor(0, 1);
    lcd.print(F("TemIn   C TemOut   C"));
    lcd.setCursor(0, 2);
    lcd.print(F("HimIn   % HimOut   %"));
    lcd.setCursor(0, 3);
    lcd.print(F("TempHeatingNow     C"));
    lcd.setCursor(0, 0);
    if (rtc.getHour() < 10)
        lcd.print(F("0"));
    lcd.print(rtc.getHour());
    lcd.setCursor(3, 0);
    if (rtc.getMinute() < 10)
        lcd.print(F("0"));
    lcd.print(rtc.getMinute());
    lcd.setCursor(8, 0);
    lcd.print(rtc.getWeekDay());
    lcd.setCursor(14, 0);
    if (rtc.getSecond() < 10) //Заменить на атмосферное давление
        lcd.print(F("0"));    //когда будет датчик
    lcd.print(rtc.getSecond());
    lcd.setCursor(6, 1);
    lcd.print(uint8_t(aht10.getTemperature()));
    lcd.setCursor(6, 2);
    lcd.print(uint8_t(aht10.getHumidity()));
    lcd.setCursor(17, 1);
    lcd.print(uint8_t(aht10.getTemperature())); //Заменить на наружный датчик
    lcd.setCursor(17, 2);
    lcd.print(uint8_t(aht10.getHumidity())); //Заменить на наружный датчик
    lcd.setCursor(17, 3);
    lcd.print(uint8_t(aht10.getTemperature())); //Заменить на потолочный датчик
}

void MenuLCD::MainMenu1()
{
    lcd.setCursor(0, 0);
    lcd.print(F("  :  Day  AtD    mmR"));
    lcd.setCursor(0, 1);
    lcd.print(F("TGrIn   C TGrOut   C"));
    lcd.setCursor(0, 2);
    lcd.print(F("HGrIn   % HGrOut   %"));
    lcd.setCursor(0, 3);
    lcd.print(F("TempCoolingNow     C"));
    lcd.setCursor(0, 0);
    if (rtc.getHour() < 10)
        lcd.print(F("0"));
    lcd.print(rtc.getHour());
    lcd.setCursor(3, 0);
    if (rtc.getMinute() < 10)
        lcd.print(F("0"));
    lcd.print(rtc.getMinute());
    lcd.setCursor(8, 0);
    lcd.print(rtc.getWeekDay());
    lcd.setCursor(14, 0);
    if (rtc.getSecond() < 10) //Заменить на атмосферное давление
        lcd.print(F("0"));    //когда будет датчик
    lcd.print(rtc.getSecond());
    lcd.setCursor(6, 1);
    lcd.print(uint8_t(aht10.getTemperature())); //Заменить на датчик температуры почвы
    lcd.setCursor(6, 2);
    lcd.print(uint8_t(aht10.getHumidity())); //Заменить на датчик влажности почвы
    lcd.setCursor(17, 1);
    lcd.print(uint8_t(aht10.getTemperature())); //Заменить на наружный датчик температуры почвы
    lcd.setCursor(17, 2);
    lcd.print(uint8_t(aht10.getHumidity())); //Заменить на наружный датчик влажности почвы
    lcd.setCursor(17, 3);
    lcd.print(uint8_t(aht10.getTemperature())); //Заменить на датчик подогрева пола
}

void MenuLCD::DateTimeSet()
{
}

void MenuLCD::DateTime()
{
    lcd.setCursor(0, 0);
    lcd.print(F("     Date/Time      "));
    lcd.setCursor(0, 1);
    lcd.print(F("Hr Mt Sc  DM Mo  Yr "));
    lcd.setCursor(0, 2);
    lcd.print(F("                    "));
    lcd.setCursor(0, 3);
    lcd.print(F("Week Day            "));
    lcd.setCursor(0, 2);
    if (rtc.getHour() < 10)
        lcd.print(F("0"));
    lcd.print(rtc.getHour());
    lcd.setCursor(3, 2);
    if (rtc.getMinute() < 10)
        lcd.print(F("0"));
    lcd.print(rtc.getMinute());
    lcd.setCursor(6, 2);
    if (rtc.getSecond() < 10)
        lcd.print(F("0"));
    lcd.print(rtc.getSecond());
    lcd.setCursor(10, 2);
    if (rtc.getDay() < 10)
        lcd.print(F("0"));
    lcd.print(rtc.getDay());
    lcd.setCursor(13, 2);
    if (rtc.getMonth() < 10)
        lcd.print(F("0"));
    lcd.print(rtc.getMonth());
    lcd.setCursor(16, 2);
    lcd.print(rtc.getYear());
    lcd.setCursor(10, 3);
    lcd.print(rtc.getWeekDay());
}

void MenuLCD::LightingSet()
{
    while (1)
    {

        enc.tick();
        lcd.blink();
        uint8_t str[]{12, 15, 12, 15, 12};
        uint8_t sim[]{1, 1, 2, 2, 3};
        uint8_t num[]{EE_SUNRISE_HOUR, EE_SUNRISE_MINUTE, EE_SUNSET_HOUR, EE_SUNSET_MINUTE, EE_DURATION_SUN};
        uint8_t i = constrain(i, 0, 4);
        if (enc.right())
            i++;
        if (enc.left())
            i--;
        lcd.setCursor(str[i], sim[i]);

        if (enc.click())
        {
            uint8_t asd = constrain(asd, 0, 59);
            enc.tick();
            if (enc.left())
                if (asd > 0)
                    (asd--);
            if (enc.right())
                (asd++);
            lcd.setCursor(10, 1);
            if (asd < 10)
                lcd.print(0);
            lcd.print(asd);
            Serial.println(asd);
            if (enc.click())
                Serial.println("Запомнил");
            if (enc.held())
                return;

            if (EEPROM.read(num[i]) == 0)
            {
                EEPROM.put(num[i], 1);
                lcd.print("On ");
                lcd.noBlink();
                return;
            }
            if (EEPROM.read(num[i]) == 1)
            {

                EEPROM.put(num[i], 0);
                lcd.print("Off");
                lcd.noBlink();
                return;
            }
        }
    }
}

void MenuLCD::Lighting()
{
    lcd.setCursor(0, 0);
    lcd.print(F("     Podsvetka      "));
    lcd.setCursor(0, 1);
    lcd.print(F("Rassvet       :     "));
    lcd.setCursor(0, 2);
    lcd.print(F("Zakat         :     "));
    lcd.setCursor(0, 3);
    lcd.print(F("Dlitelnost       min"));
    lcd.setCursor(12, 1);
    lcd.print(EEPROM.read(EE_SUNRISE_HOUR));
    lcd.setCursor(15, 1);
    lcd.print(EEPROM.read(EE_SUNRISE_MINUTE));
    lcd.setCursor(12, 2);
    lcd.print(EEPROM.read(EE_SUNSET_HOUR));
    lcd.setCursor(15, 2);
    lcd.print(EEPROM.read(EE_SUNSET_MINUTE));
    lcd.setCursor(12, 3);
    lcd.print(EEPROM.read(EE_DURATION_SUN));
}

void MenuLCD::HeatingSet()
{
}

void MenuLCD::Heating()
{
    lcd.setCursor(0, 0);
    lcd.print(F("   Podogrev pola    "));
    lcd.setCursor(0, 1);
    lcd.print(F("Rassv   :   TmpD   C"));
    lcd.setCursor(0, 2);
    lcd.print(F("Zakat   :   TmpN   C"));
    lcd.setCursor(0, 3);
    lcd.print(F("Heating PWM         "));
    lcd.setCursor(6, 1);
    lcd.print(EEPROM.read(EE_SUNRISE_HOUR));
    lcd.setCursor(9, 1);
    lcd.print(EEPROM.read(EE_SUNRISE_MINUTE));
    lcd.setCursor(17, 1);
    lcd.print(EEPROM.read(EE_TEMP_HEATING_DAY));
    lcd.setCursor(6, 2);
    lcd.print(EEPROM.read(EE_SUNSET_HOUR));
    lcd.setCursor(9, 2);
    lcd.print(EEPROM.read(EE_SUNSET_MINUTE));
    lcd.setCursor(17, 2);
    lcd.print(EEPROM.read(EE_TEMP_HEATING_NIGHT));
    lcd.setCursor(17, 3);
    lcd.print(EEPROM.read(EE_HEATING_PWM));
}

void MenuLCD::CoolingSet()
{
}

void MenuLCD::Cooling()
{

    lcd.setCursor(0, 0);
    lcd.print(F("     Fortochka      "));
    lcd.setCursor(0, 1);
    lcd.print(F("OpnTOut>  C&Tpot>  C"));
    lcd.setCursor(0, 2);
    lcd.print(F("ClsTOut<  C&Tpot<  C"));
    lcd.setCursor(0, 3);
    lcd.print(F("CoolPWM    Delay   m"));
    lcd.setCursor(8, 1);
    lcd.print(EEPROM.read(EE_TEMP_COOLING_OUT_ON));
    lcd.setCursor(17, 1);
    lcd.print(EEPROM.read(EE_TEMP_COOLING_IN_ON));
    lcd.setCursor(8, 2);
    lcd.print(EEPROM.read(EE_TEMP_COOLING_OUT_OFF));
    lcd.setCursor(17, 2);
    lcd.print(EEPROM.read(EE_TEMP_COOLING_IN_OFF));
    lcd.setCursor(8, 3);
    lcd.print(EEPROM.read(EE_COOLING_PWM));
    lcd.setCursor(17, 3);
    lcd.print(EEPROM.read(EE_COOLING_DRV_STOP_DELAY));
}

void MenuLCD::WateringSet()
{
}

void MenuLCD::Watering()
{
    lcd.setCursor(0, 0);
    lcd.print(F("MO  FR   Poliv   Vlv"));
    lcd.setCursor(0, 1);
    lcd.print(F("TU  SA   On     :   "));
    lcd.setCursor(0, 2);
    lcd.print(F("WE  SU   Time    min"));
    lcd.setCursor(0, 3);
    lcd.print(F("TH  >>              "));
    lcd.setCursor(16, 0);
    lcd.print(numValve);
    // lcd.setCursor(0, 1);
    // lcd.print(0);
}