#include <Arduino.h>
#include <data.h>
#include <DS3231.h>
#include <AHT10.h>
#include <menu.h>
#include <EncButton.h>
#include <LiquidCrystal_I2C.h>

AHT10 aht10;
DS3231 rtc;
LiquidCrystal_I2C lcd(0x27, 20, 4);
EncButton<EB_TICK, 2, 3, 4> enc;
Menu menu;

void setup()
{
  lcd.init();
  lcd.backlight();
  Serial.begin(115200);
  enc.getState();
}
void loop()
{
  menu.mainMenu();
}
