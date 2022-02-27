#include <data.h>

MenuLCD menu;
LiquidCrystal_I2C lcd(0x27, 20, 4);
EncButton<EB_TICK, 2, 3, 4> enc;
PCF8574 portPoliv;
AHT10 aht10;
DS3231 rtc;

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
  menu.Poliv();
}
