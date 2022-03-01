#include <data.h>

MenuLCD menu;
LiquidCrystal_I2C lcd(0x27, 20, 4);
EncButton<EB_TICK, 2, 3, 0> enc;
PCF8574 portPoliv;
AHT10 aht10;
DS3231 rtc;
Sun sun;
Heat heat;
Poliv poliv;
MicroDS18B20<DALLAS_1> ds;

void setup()
{
  pinMode(LIGHT, OUTPUT);
  pinMode(HEAT, OUTPUT);
  lcd.init();
  lcd.backlight();
  Serial.begin(115200);
  enc.getState();
}
void loop()
{
  sun.lighting();
  heat.heating();

  menu.mainMenu();
  menu.Poliv();
}
