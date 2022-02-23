#include <menu.h>



void Menu::mainMenu()
{
    lcd.setCursor(0, 0);
    lcd.print(F("DS3231   "));
    lcd.setCursor(9, 0);
    if (rtc.getDay() < 10)
        lcd.print(F("0"));
    lcd.print(rtc.getDay());
    lcd.setCursor(12, 0);
    if (rtc.getMonth() < 10)
        lcd.print(F("0"));
    lcd.print(rtc.getMonth());
    lcd.setCursor(15, 0);
    lcd.print(rtc.getYear());
    lcd.setCursor(0, 1);
    lcd.print(F("DS3231 time "));
    lcd.setCursor(12, 1);
    if (rtc.getHour() < 10)
        lcd.print(F("0"));
    lcd.print(rtc.getHour());
    lcd.setCursor(15, 1);
    if (rtc.getMinute() < 10)
        lcd.print(F("0"));
    lcd.print(rtc.getMinute());
    lcd.setCursor(18, 1);
    if (rtc.getSecond() < 10)
        lcd.print(F("0"));
    lcd.print(rtc.getSecond());
    lcd.setCursor(0, 2);
    lcd.print(F("Temperature    "));
    lcd.setCursor(15, 2);
    lcd.print(int8_t (aht10.getTemperature()));
    lcd.setCursor(0, 3);
    lcd.print(F("Humidity   "));
    lcd.setCursor(11, 3);
    lcd.print(rtc.getWeekDay());
    lcd.setCursor(15, 3);
    lcd.print(int8_t (aht10.getHumidity()));
}