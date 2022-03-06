#include <menu.h>
extern LiquidCrystal_I2C lcd;
extern AHT10 aht10;
extern DS3231 rtc;
extern uint8_t numValve;
extern EncButton<EB_TICK, 3, 2, 0> enc;
elapsedMillis t;

void MenuLCD::SetupMenuSet()
{
    while (1)
    {
        enc.tick();
        lcd.blink();
        uint8_t sim[]{8, 8, 8, 8};
        uint8_t str[]{0, 1, 2, 3};
        uint8_t num[]{EE_COOLING_ON, EE_HEATING_ON, EE_WATERING_ON, EE_LOGGING_ON};
        uint8_t i = constrain(i, 0, 3);
        if (enc.right())
            i++;
        if (enc.left())
            i--;
        lcd.setCursor(sim[i], str[i]);

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
    while (1)
    {

        enc.tick();
        lcd.blink();
        uint8_t psp[7]{};
        uint8_t sim[]{0, 3, 6, 10, 13, 18, 10};
        uint8_t str[]{2, 2, 2, 2, 2, 2, 3};
        uint8_t i = constrain(i, 0, 6);
        if (enc.right())
            i++;
        if (enc.left())
            i--;
        lcd.setCursor(sim[i], str[i]);

        if (enc.click())
        {

            while (1)
            {
                enc.tick();
                psp[0] = constrain(enc.counter, 0, 23);
                psp[1] = constrain(enc.counter, 0, 59);
                psp[2] = constrain(enc.counter, 0, 59);
                psp[3] = constrain(enc.counter, 1, 31);
                psp[4] = constrain(enc.counter, 1, 12);
                psp[5] = constrain(enc.counter, 0, 99);
                psp[6] = constrain(enc.counter, 1, 7);

                if (enc.leftH())
                    if (psp[i] > 0)
                        (psp[i]--);
                if (enc.rightH())
                    (psp[i]++);
                lcd.setCursor((sim[i]), str[i]);
                if (psp[i] < 10)
                    lcd.print(0);
                lcd.print(psp[i]);
                if (enc.click())
                {
                    if (i == 0)
                        rtc.setHour(psp[i]);
                    if (i == 1)
                        rtc.setMinute(psp[i]);
                    if (i == 2)
                        rtc.setSecond(psp[i]);
                    if (i == 3)
                        rtc.setDay(psp[i]);
                    if (i == 4)
                        rtc.setMonth(psp[i]);
                    if (i == 5)
                        rtc.setYear(psp[i]);
                    if (i == 6)
                        rtc.setWeekDay(psp[i]);
                    lcd.noBlink();
                    return;
                }
            }
        }
    }
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
    if (rtc.getWeekDay() < 10)
        lcd.print(F("0"));
    lcd.print(rtc.getWeekDay());
}

void MenuLCD::LightingSet()
{
    while (1)
    {

        enc.tick();
        lcd.blink();
        uint8_t psp[5]{};
        uint8_t sim[]{12, 15, 12, 15, 12};
        uint8_t str[]{1, 1, 2, 2, 3};
        uint8_t num[]{EE_SUNRISE_HOUR, EE_SUNRISE_MINUTE, EE_SUNSET_HOUR, EE_SUNSET_MINUTE, EE_DURATION_SUN};
        uint8_t i = constrain(i, 0, 4);
        if (enc.right())
            i++;
        if (enc.left())
            i--;
        lcd.setCursor(sim[i], str[i]);

        if (enc.click())
        {

            while (1)
            {
                enc.tick();
                psp[0] = constrain(enc.counter, 0, 23);
                psp[1] = constrain(enc.counter, 0, 59);
                psp[2] = constrain(enc.counter, 0, 23);
                psp[3] = constrain(enc.counter, 0, 59);
                psp[4] = constrain(enc.counter, 0, 59);

                if (enc.leftH())
                    if (psp[i] > 0)
                        (psp[i]--);
                if (enc.rightH())
                    (psp[i]++);
                lcd.setCursor((sim[i]), str[i]);
                if (psp[i] < 10)
                    lcd.print(0);
                lcd.print(psp[i]);
                if (enc.click())
                {
                    EEPROM.put(num[i], psp[i]);
                    lcd.noBlink();
                    return;
                }
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
    while (1)
    {

        enc.tick();
        lcd.blink();
        uint8_t psp[7]{};
        uint8_t sim[]{6, 9, 17, 6, 9, 17, 17};
        uint8_t str[]{1, 1, 1, 2, 2, 2, 3};
        uint8_t num[]{EE_SUNRISE_HOUR, EE_SUNRISE_MINUTE, EE_TEMP_HEATING_DAY, EE_SUNSET_HOUR, EE_SUNSET_MINUTE, EE_TEMP_HEATING_NIGHT, EE_HEATING_PWM};
        uint8_t i = constrain(i, 0, 6);
        if (enc.right())
            i++;
        if (enc.left())
            i--;
        lcd.setCursor(sim[i], str[i]);

        if (enc.click())
        {

            while (1)
            {
                enc.tick();
                psp[0] = constrain(enc.counter, 0, 23);
                psp[1] = constrain(enc.counter, 0, 59);
                psp[2] = constrain(enc.counter, 5, 40);
                psp[3] = constrain(enc.counter, 0, 23);
                psp[4] = constrain(enc.counter, 0, 59);
                psp[5] = constrain(enc.counter, 5, 40);
                psp[6] = constrain(enc.counter, 0, 255);

                if (enc.leftH())
                    if (psp[i] > 0)
                        (psp[i]--);
                if (enc.rightH())
                    (psp[i]++);
                lcd.setCursor((sim[i]), str[i]);
                if (psp[i] < 10)
                    lcd.print(0);
                lcd.print(psp[i]);
                if (enc.click())
                {
                    EEPROM.put(num[i], psp[i]);
                    lcd.noBlink();
                    return;
                }
            }
        }
    }
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
    while (1)
    {
        enc.tick();
        lcd.blink();
        uint8_t psp[6]{};
        uint8_t sim[]{8, 17, 8, 17, 8, 17};
        uint8_t str[]{1, 1, 2, 2, 3, 3};
        uint8_t num[]{EE_TEMP_COOLING_OUT_OPEN, EE_TEMP_COOLING_IN_OPEN, EE_TEMP_COOLING_OUT_CLOSE, EE_TEMP_COOLING_IN_CLOSE, EE_COOLING_PWM, EE_COOLING_DRV_STOP_DELAY};
        uint8_t i = constrain(i, 0, 5);
        if (enc.right())
            i++;
        if (enc.left())
            i--;
        lcd.setCursor(sim[i], str[i]);

        if (enc.click())
        {
            while (1)
            {
                enc.tick();
                psp[0] = constrain(enc.counter, 10, 50);
                psp[1] = constrain(enc.counter, 10, 50);
                psp[2] = constrain(enc.counter, 10, 30);
                psp[3] = constrain(enc.counter, 10, 30);
                psp[4] = constrain(enc.counter, 0, 255);
                psp[5] = constrain(enc.counter, 0, 90);

                if (enc.leftH())
                    if (psp[i] > 0)
                        (psp[i]--);
                if (enc.rightH())
                    (psp[i]++);
                lcd.setCursor((sim[i]), str[i]);
                if (psp[i] < 10)
                    lcd.print(0);
                lcd.print(psp[i]);
                if (enc.click())
                {
                    EEPROM.put(num[i], psp[i]);
                    lcd.noBlink();
                    return;
                }
            }
        }
    }
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
    lcd.print(F("CoolPWM    Delay   s"));
    lcd.setCursor(8, 1);
    lcd.print(EEPROM.read(EE_TEMP_COOLING_OUT_OPEN));
    lcd.setCursor(17, 1);
    lcd.print(EEPROM.read(EE_TEMP_COOLING_IN_OPEN));
    lcd.setCursor(8, 2);
    lcd.print(EEPROM.read(EE_TEMP_COOLING_OUT_CLOSE));
    lcd.setCursor(17, 2);
    lcd.print(EEPROM.read(EE_TEMP_COOLING_IN_CLOSE));
    lcd.setCursor(8, 3);
    lcd.print(EEPROM.read(EE_COOLING_PWM));
    lcd.setCursor(17, 3);
    lcd.print(EEPROM.read(EE_COOLING_DRV_STOP_DELAY));
}

void MenuLCD::WateringSet()
{

    uint8_t i = constrain(enc.counter, 7, 13);

    uint8_t SetWeekDays;
    uint8_t SetHours;
    uint8_t SetMinutes;
    uint8_t SetLong;
    switch (i)
    {
    case 7:

        SetWeekDays = EEPROM.read(EE_VLV_1_SET_WEEK_DAYS);
        SetHours = EEPROM.read(EE_VLV_1_SET_HOUR);
        SetMinutes = EEPROM.read(EE_VLV_1_SET_MINUTE);
        SetLong = EEPROM.read(EE_VLV_1_SET_LONG);
        break;
    case 8:

        SetWeekDays = EEPROM.read(EE_VLV_2_SET_WEEK_DAYS);
        SetHours = EEPROM.read(EE_VLV_2_SET_HOUR);
        SetMinutes = EEPROM.read(EE_VLV_2_SET_MINUTE);
        SetLong = EEPROM.read(EE_VLV_2_SET_LONG);
        break;
    case 9:

        SetWeekDays = EEPROM.read(EE_VLV_3_SET_WEEK_DAYS);
        SetHours = EEPROM.read(EE_VLV_3_SET_HOUR);
        SetMinutes = EEPROM.read(EE_VLV_3_SET_MINUTE);
        SetLong = EEPROM.read(EE_VLV_3_SET_LONG);
        break;
    case 10:

        SetWeekDays = EEPROM.read(EE_VLV_4_SET_WEEK_DAYS);
        SetHours = EEPROM.read(EE_VLV_4_SET_HOUR);
        SetMinutes = EEPROM.read(EE_VLV_4_SET_MINUTE);
        SetLong = EEPROM.read(EE_VLV_4_SET_LONG);
        break;
    case 11:

        SetWeekDays = EEPROM.read(EE_VLV_5_SET_WEEK_DAYS);
        SetHours = EEPROM.read(EE_VLV_5_SET_HOUR);
        SetMinutes = EEPROM.read(EE_VLV_5_SET_MINUTE);
        SetLong = EEPROM.read(EE_VLV_5_SET_LONG);
        break;
    case 12:

        SetWeekDays = EEPROM.read(EE_VLV_6_SET_WEEK_DAYS);
        SetHours = EEPROM.read(EE_VLV_6_SET_HOUR);
        SetMinutes = EEPROM.read(EE_VLV_6_SET_MINUTE);
        SetLong = EEPROM.read(EE_VLV_6_SET_LONG);
        break;
    case 13:

        SetWeekDays = EEPROM.read(EE_VLV_7_SET_WEEK_DAYS);
        SetHours = EEPROM.read(EE_VLV_7_SET_HOUR);
        SetMinutes = EEPROM.read(EE_VLV_7_SET_MINUTE);
        SetLong = EEPROM.read(EE_VLV_7_SET_LONG);
        break;
    }

    while (1)
    {
        enc.tick();
        lcd.blink();
        uint8_t psp[10]{};
        uint8_t sim[]{2, 2, 2, 2, 6, 6, 6, 14, 17, 14};
        uint8_t str[]{0, 1, 2, 3, 0, 1, 2, 1, 1, 2};
        // uint8_t num[]{EE_TEMP_COOLING_OUT_OPEN, EE_TEMP_COOLING_IN_OPEN, EE_TEMP_COOLING_OUT_CLOSE, EE_TEMP_COOLING_IN_CLOSE, EE_COOLING_PWM, EE_COOLING_DRV_STOP_DELAY};
        uint8_t i = constrain(i, 0, 9);
        if (enc.right())
            i++;
        if (enc.left())
            i--;
        lcd.setCursor(sim[i], str[i]);

        if (enc.click())
        {
            while (1)
            {
                enc.tick();
                psp[0] = constrain(enc.counter, 0, 1);
                psp[1] = constrain(enc.counter, 0, 1);
                psp[2] = constrain(enc.counter, 0, 1);
                psp[3] = constrain(enc.counter, 0, 1);
                psp[4] = constrain(enc.counter, 0, 1);
                psp[5] = constrain(enc.counter, 0, 1);
                psp[6] = constrain(enc.counter, 0, 1);
                psp[7] = constrain(enc.counter, 0, 23);
                psp[8] = constrain(enc.counter, 0, 59);
                psp[9] = constrain(enc.counter, 0, 90);

                if (enc.leftH())
                    if (psp[i] > 0)
                        (psp[i]--);
                if (enc.rightH())
                    (psp[i]++);
                lcd.setCursor((sim[i]), str[i]);
                if ((psp[i] < 10) && (i > 6))
                    lcd.print(0);
                lcd.print(psp[i]);
                if (enc.click())
                {
                    EEPROM.put(num[i], psp[i]);
                    lcd.noBlink();
                    return;
                }
            }
        }
    }
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

    uint8_t SetHours;
    uint8_t SetMinutes;
    uint8_t SetLong;
    uint8_t SetWeekDays;
    uint8_t i = constrain(enc.counter, 7, 13);

    switch (i)
    {
    case 7:
        SetWeekDays = EEPROM.read(EE_VLV_1_SET_WEEK_DAYS);
        SetHours = EEPROM.read(EE_VLV_1_SET_HOUR);
        SetMinutes = EEPROM.read(EE_VLV_1_SET_MINUTE);
        SetLong = EEPROM.read(EE_VLV_1_SET_LONG);
        break;
    case 8:
        SetWeekDays = EEPROM.read(EE_VLV_2_SET_WEEK_DAYS);
        SetHours = EEPROM.read(EE_VLV_2_SET_HOUR);
        SetMinutes = EEPROM.read(EE_VLV_2_SET_MINUTE);
        SetLong = EEPROM.read(EE_VLV_2_SET_LONG);
        break;
    case 9:
        SetWeekDays = EEPROM.read(EE_VLV_3_SET_WEEK_DAYS);
        SetHours = EEPROM.read(EE_VLV_3_SET_HOUR);
        SetMinutes = EEPROM.read(EE_VLV_3_SET_MINUTE);
        SetLong = EEPROM.read(EE_VLV_3_SET_LONG);
        break;
    case 10:
        SetWeekDays = EEPROM.read(EE_VLV_4_SET_WEEK_DAYS);
        SetHours = EEPROM.read(EE_VLV_4_SET_HOUR);
        SetMinutes = EEPROM.read(EE_VLV_4_SET_MINUTE);
        SetLong = EEPROM.read(EE_VLV_4_SET_LONG);
        break;
    case 11:
        SetWeekDays = EEPROM.read(EE_VLV_5_SET_WEEK_DAYS);
        SetHours = EEPROM.read(EE_VLV_5_SET_HOUR);
        SetMinutes = EEPROM.read(EE_VLV_5_SET_MINUTE);
        SetLong = EEPROM.read(EE_VLV_5_SET_LONG);
        break;
    case 12:
        SetWeekDays = EEPROM.read(EE_VLV_6_SET_WEEK_DAYS);
        SetHours = EEPROM.read(EE_VLV_6_SET_HOUR);
        SetMinutes = EEPROM.read(EE_VLV_6_SET_MINUTE);
        SetLong = EEPROM.read(EE_VLV_6_SET_LONG);
        break;
    case 13:
        SetWeekDays = EEPROM.read(EE_VLV_7_SET_WEEK_DAYS);
        SetHours = EEPROM.read(EE_VLV_7_SET_HOUR);
        SetMinutes = EEPROM.read(EE_VLV_7_SET_MINUTE);
        SetLong = EEPROM.read(EE_VLV_7_SET_LONG);
        break;
    }

    enum WeekDay : uint8_t

    {
        MO = 1 << 0,
        TU = 1 << 1,
        WE = 1 << 2,
        TH = 1 << 3,
        FR = 1 << 4,
        SA = 1 << 5,
        SU = 1 << 6,
        PUST = 1 << 7
    };

    bool on[7]{};
    uint8_t wd;
    switch (wd)
    {
    case 1:
        on[0] = (MO | SetWeekDays);
        break;
    case 2:
        on[1] = (TU | SetWeekDays);
        break;
    case 3:
        on[2] = (WE | SetWeekDays);
        break;
    case 4:
        on[3] = (TH | SetWeekDays);
        break;
    case 5:
        on[4] = (FR | SetWeekDays);
        break;
    case 6:
        on[5] = (SA | SetWeekDays);
        break;
    case 7:
        on[6] = (SU | SetWeekDays);
        break;
    }
    lcd.setCursor(2, 0);
    lcd.print(on[0]);
    lcd.setCursor(2, 1);
    lcd.print(on[1]);
    lcd.setCursor(2, 2);
    lcd.print(on[2]);
    lcd.setCursor(2, 3);
    lcd.print(on[3]);
    lcd.setCursor(6, 0);
    lcd.print(on[4]);
    lcd.setCursor(6, 1);
    lcd.print(on[5]);
    lcd.setCursor(6, 2);
    lcd.print(on[6]);
    lcd.setCursor(16, 0);
    lcd.print(i - 6);
    lcd.setCursor(14, 1);
    lcd.print(SetHours);
    lcd.setCursor(17, 1);
    lcd.print(SetMinutes);
    lcd.setCursor(14, 2);
    lcd.print(SetLong);
}
