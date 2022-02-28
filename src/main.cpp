#include <data.h>

MenuLCD menu;
LiquidCrystal_I2C lcd(0x27, 20, 4);
EncButton<EB_TICK, 2, 3, 4> enc;
PCF8574 portPoliv;
AHT10 aht10;
DS3231 rtc;
Sun sun;

void setup()
{
  pinMode(LIGHT, OUTPUT);
  lcd.init();
  lcd.backlight();
  Serial.begin(115200);
  enc.getState();
}
void loop()
{
  sun.day();
  sun.sunset();
  sun.night();
  sun.sunrise();
  menu.mainMenu();
  menu.Poliv();
}
