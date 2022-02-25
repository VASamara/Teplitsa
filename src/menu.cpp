#include <menu.h>

void Menu::mainMenu()
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
    lcd.setCursor(0, 3);
    if (rtc.getMinute() < 10)
        lcd.print(F("0"));
    lcd.print(rtc.getMinute());
    lcd.setCursor(0, 8);
    lcd.print(rtc.getWeekDay());
    lcd.setCursor(0, 13);
    if (rtc.getSecond() < 10) //Заменить на атмосферное давление
        lcd.print(F("0"));    //когда будет датчик
    lcd.print(rtc.getSecond());
    lcd.setCursor(2, 0);
    lcd.print(uint8_t(aht10.getTemperature()));
    lcd.setCursor(2, 4);
    lcd.print(uint8_t(aht10.getHumidity()));
    lcd.setCursor(2, 8);
    lcd.print(uint8_t(aht10.getTemperature())); //Заменить на наружный датчик
    lcd.setCursor(2, 12);
    lcd.print(uint8_t(aht10.getHumidity())); //Заменить на наружный датчик
    lcd.setCursor(2, 16);
    lcd.print(uint8_t(aht10.getHumidity())); //Заменить на потолочный датчик
}

void Menu::mainMenu1()
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
    lcd.setCursor(0, 3);
    if (rtc.getMinute() < 10)
        lcd.print(F("0"));
    lcd.print(rtc.getMinute());
    lcd.setCursor(0, 8);
    lcd.print(rtc.getWeekDay());
    lcd.setCursor(0, 13);
    if (rtc.getSecond() < 10) //Заменить на атмосферное давление
        lcd.print(F("0"));    //когда будет датчик
    lcd.print(rtc.getSecond());
    lcd.setCursor(2, 0);
    lcd.print(uint8_t(aht10.getTemperature())); //Заменить на датчик температуры почвы
    lcd.setCursor(2, 4);
    lcd.print(uint8_t(aht10.getHumidity())); //Заменить на датчик влажности почвы
    lcd.setCursor(2, 8);
    lcd.print(uint8_t(aht10.getTemperature())); //Заменить на наружный датчик температуры почвы
    lcd.setCursor(2, 12);
    lcd.print(uint8_t(aht10.getHumidity())); //Заменить на наружный датчик влажности почвы
    lcd.setCursor(2, 16);
    lcd.print(uint8_t(aht10.getTemperature())); //Заменить на датчик подогрева пола
}

void Menu::DateTime()
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

void Menu::Podsvetka()
{
    lcd.setCursor(0, 0);
    lcd.print(F("     Podsvetka      "));
    lcd.setCursor(0, 1);
    lcd.print(F("Rassv   :   Dlit   m"));
    lcd.setCursor(0, 2);
    lcd.print(F("Zakat   :   Dlit   m"));
    lcd.setCursor(0, 3);
    lcd.print(F(">Press to settings  "));
    lcd.setCursor(6, 1);
    lcd.print(EEPROM.read(0));
    lcd.setCursor(9, 1);
    lcd.print(EEPROM.read(1));
    lcd.setCursor(17, 1);
    lcd.print(EEPROM.read(2));
    lcd.setCursor(6, 2);
    lcd.print(EEPROM.read(3));
    lcd.setCursor(9, 2);
    lcd.print(EEPROM.read(4));
    lcd.setCursor(17, 2);
    lcd.print(EEPROM.read(5));
}

void Menu::Podogrev()
{
    lcd.setCursor(0, 0);
    lcd.print(F("   Podogrev pola    "));
    lcd.setCursor(0, 1);
    lcd.print(F("Rassv   :   TmpD   C"));
    lcd.setCursor(0, 2);
    lcd.print(F("Zakat   :   TmpN   C"));
    lcd.setCursor(0, 3);
    lcd.print(F(">Press to settings  "));
    lcd.setCursor(6, 1);
    lcd.print(EEPROM.read(6));
    lcd.setCursor(9, 1);
    lcd.print(EEPROM.read(7));
    lcd.setCursor(17, 1);
    lcd.print(EEPROM.read(8));
    lcd.setCursor(6, 2);
    lcd.print(EEPROM.read(9));
    lcd.setCursor(9, 2);
    lcd.print(EEPROM.read(10));
    lcd.setCursor(17, 2);
    lcd.print(EEPROM.read(11));
}
void Menu::Fortochka()
{

    lcd.setCursor(0, 0);
    lcd.print(F("     Fortochka      "));
    lcd.setCursor(0, 1);
    lcd.print(F("OpnTOut>  C&Tpot>  C"));
    lcd.setCursor(0, 2);
    lcd.print(F("ClsTOut<  C&Tpot<  C"));
    lcd.setCursor(0, 3);
    lcd.print(F(">Press to settings  "));
    lcd.setCursor(8, 1);
    lcd.print(EEPROM.read(12));
    lcd.setCursor(17, 1);
    lcd.print(EEPROM.read(13));
    lcd.setCursor(8, 2);
    lcd.print(EEPROM.read(14));
    lcd.setCursor(17, 2);
    lcd.print(EEPROM.read(15));
}
void Menu::Poliv(uint8_t valve)
{
    lcd.setCursor(0, 0);
    lcd.print(F("1234567WD Poliv Vlv "));
    lcd.setCursor(0, 1);
    lcd.print(F("        On  :  Min  "));
    lcd.setCursor(0, 2);
    lcd.print(F("        On  :  Min  "));
    lcd.setCursor(0, 3);
    lcd.print(F(">Press to settings  "));
    lcd.setCursor(19, 0);
    lcd.print(valve);
    lcd.setCursor(0, 1);
    lcd.print(0);
}