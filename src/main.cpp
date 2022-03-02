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
IO_PORT bitValve;

void setup()
{
  pinMode(LIGHT, OUTPUT);
  pinMode(HEAT, OUTPUT);
  pinMode(DRV_PWM, OUTPUT);
  pinMode(DRV_SIG_1, OUTPUT);
  pinMode(DRV_SIG_2, OUTPUT);
  lcd.init();
  lcd.backlight();
  Serial.begin(115200);
  enc.getState();
  menu.mainMenu();
}
void loop()
{
  enc.tick();
  if (enc.click())
    Serial.println("click");
  if (enc.held())
  {
    menu.SetupMenu();
  }
  if (enc.turn())
    menu.mainMenu1();

// un.Lighting();
// heat.Heating();

// menu.Poliv();
}
