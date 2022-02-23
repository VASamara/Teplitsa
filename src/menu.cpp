#include "menu.h"



void Menu::mainMenu()
{
    lcd.setCursor(0, 0);
    lcd.print(F("DS3231   "));
    lcd.setCursor(9, 0);
    if (rtc.getDate() < 10)
        lcd.print(F("0"));
    lcd.print(rtc.getDate());
    lcd.setCursor(12, 0);
    if (rtc.getMonth() < 10)
        lcd.print(F("0"));
    lcd.print(rtc.getMonth());
    lcd.setCursor(15, 0);
    lcd.print(rtc.getYear());
    lcd.setCursor(0, 1);
    lcd.print(F("DS3231 time "));
    lcd.setCursor(12, 1);
    if (rtc.getHours() < 10)
        lcd.print(F("0"));
    lcd.print(rtc.getHours());
    lcd.setCursor(15, 1);
    if (rtc.getMinutes() < 10)
        lcd.print(F("0"));
    lcd.print(rtc.getMinutes());
    lcd.setCursor(18, 1);
    if (rtc.getSeconds() < 10)
        lcd.print(F("0"));
    lcd.print(rtc.getSeconds());
    lcd.setCursor(0, 2);
    lcd.print(F("Temperature    "));
    lcd.setCursor(15, 2);
    lcd.print(int8_t (aht10.readTemperature()));
    lcd.setCursor(0, 3);
    lcd.print(F("Humidity   "));
    lcd.setCursor(11, 3);
    lcd.print(rtc.getDay());
    lcd.setCursor(15, 3);
    lcd.print(int8_t (aht10.readHumidity()));
}