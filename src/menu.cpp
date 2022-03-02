#include <menu.h>
extern LiquidCrystal_I2C lcd;
extern AHT10 aht10;
extern DS3231 rtc;
extern IO_PORT bitValve;

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

}
void MenuLCD::mainMenu()
{
    lcd.setCursor(0, 0);
    lcd.print(F("  :  Day  AtD   mmRs"));
    lcd.setCursor(0, 1);
    lcd.print(F("TIn HIn TOutHOutTpot"));
    lcd.setCursor(0, 2);
    lcd.print(F("  C   %   C   %   C "));
    lcd.setCursor(0, 3);
    lcd.print(F(">Press to settings  "));
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
    lcd.setCursor(13, 0);
    if (rtc.getSecond() < 10) //Заменить на атмосферное давление
        lcd.print(F("0"));    //когда будет датчик
    lcd.print(rtc.getSecond());
    lcd.setCursor(0, 2);
    lcd.print(uint8_t(aht10.getTemperature()));
    lcd.setCursor(4, 2);
    lcd.print(uint8_t(aht10.getHumidity()));
    lcd.setCursor(8, 2);
    lcd.print(uint8_t(aht10.getTemperature())); //Заменить на наружный датчик
    lcd.setCursor(12, 2);
    lcd.print(uint8_t(aht10.getHumidity())); //Заменить на наружный датчик
    lcd.setCursor(16, 2);
    lcd.print(uint8_t(aht10.getHumidity())); //Заменить на потолочный датчик
}

void MenuLCD::mainMenu1()
{
    lcd.setCursor(0, 0);
    lcd.print(F("  :  Day  AtD   mmRs"));
    lcd.setCursor(0, 1);
    lcd.print(F("TPInHPInTPOtHPOtTpol"));
    lcd.setCursor(0, 2);
    lcd.print(F("  C   %   C   %   C "));
    lcd.setCursor(0, 3);
    lcd.print(F(">Press to settings  "));
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
    lcd.setCursor(13, 0);
    if (rtc.getSecond() < 10) //Заменить на атмосферное давление
        lcd.print(F("0"));    //когда будет датчик
    lcd.print(rtc.getSecond());
    lcd.setCursor(0, 2);
    lcd.print(uint8_t(aht10.getTemperature())); //Заменить на датчик температуры почвы
    lcd.setCursor(4, 2);
    lcd.print(uint8_t(aht10.getHumidity())); //Заменить на датчик влажности почвы
    lcd.setCursor(8, 2);
    lcd.print(uint8_t(aht10.getTemperature())); //Заменить на наружный датчик температуры почвы
    lcd.setCursor(12, 2);
    lcd.print(uint8_t(aht10.getHumidity())); //Заменить на наружный датчик влажности почвы
    lcd.setCursor(16, 2);
    lcd.print(uint8_t(aht10.getTemperature())); //Заменить на датчик подогрева пола
}

void MenuLCD::DateTime()
{
    lcd.setCursor(0, 0);
    lcd.print(F("     Date/Time      "));
    lcd.setCursor(0, 1);
    lcd.print(F("Hr Mt Sc DM Mo WD Yr"));
    lcd.setCursor(0, 2);
    lcd.print(F("                    "));
    lcd.setCursor(0, 3);
    lcd.print(F(">Press to settings  "));
    lcd.setCursor(0, 3);
    if (rtc.getHour() < 10)
        lcd.print(F("0"));
    lcd.print(rtc.getHour());
    lcd.setCursor(3, 3);
    if (rtc.getMinute() < 10)
        lcd.print(F("0"));
    lcd.print(rtc.getMinute());
    lcd.setCursor(6, 3);
    if (rtc.getSecond() < 10)
        lcd.print(F("0"));
    lcd.print(rtc.getSecond());
    lcd.setCursor(9, 3);
    if (rtc.getDay() < 10)
        lcd.print(F("0"));
    lcd.print(rtc.getDay());
    lcd.setCursor(12, 3);
    if (rtc.getMonth() < 10)
        lcd.print(F("0"));
    lcd.print(rtc.getMonth());
    lcd.setCursor(15, 3);
    lcd.print(rtc.getWeekDay());
    lcd.setCursor(16, 3);
    lcd.print(rtc.getYear());
}

void MenuLCD::Lighting()
{
    lcd.setCursor(0, 0);
    lcd.print(F("     Podsvetka      "));
    lcd.setCursor(0, 1);
    lcd.print(F("Rassvet        :    "));
    lcd.setCursor(0, 2);
    lcd.print(F("Zakat          :    "));
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
void MenuLCD::Poliv()
{
    lcd.setCursor(0, 0);
    lcd.print(F("MO  FR    Poliv Vlv "));
    lcd.setCursor(0, 1);
    lcd.print(F("TU  SA   On     :   "));
    lcd.setCursor(0, 2);
    lcd.print(F("WE  SU   Time    min"));
    lcd.setCursor(0, 3);
    lcd.print(F("TH  "));
    lcd.setCursor(16, 0);
    lcd.print(bitValve);
    lcd.setCursor(0, 1);
    lcd.print(0);
}