#include <data.h>

MenuLCD menu;
LiquidCrystal_I2C lcd(0x27, 20, 4);
EncButton<EB_TICK, 3, 2, 0> enc;
PCF8574 portPoliv;
AHT10 aht10;
DS3231 rtc;
Sun sun;
Heat heat;
Poliv poliv;
MicroDS18B20<DALLAS_1> ds;
IO_PORT bitValve;
uint8_t numValve = constrain(numValve, 1, 7);

void setup()
{
  pinMode(LIGHT, OUTPUT);
  pinMode(HEAT, OUTPUT);
  pinMode(DRV_PWM, OUTPUT);
  pinMode(DRV_SIG_1, OUTPUT);
  pinMode(DRV_SIG_2, OUTPUT);
  lcd.init();
  lcd.backlight();
  //Serial.begin(115200);
  enc.getState();
  menu.MainMenu();
  numValve = 1;
}
void loop()
{
  if ((EEPROM.read(bitRead(EE_OPTION_ON, 0))) != 0)
    heat.Cooling();
  if ((EEPROM.read(bitRead(EE_OPTION_ON, 0))) != 0)
    heat.Heating();
  if ((EEPROM.read(bitRead(EE_OPTION_ON, 0))) != 0)
    poliv.SetPoliv();

  enc.tick();
  if(enc.held())
  heat.ButCooling();
  if (enc.right() or enc.left())
  {
    enc.counter = constrain(enc.counter, 0, 13);
    //Serial.println(enc.counter);
    switch (enc.counter)
    {
    case 0:
      menu.MainMenu();
      break;
    case 1:
      menu.MainMenu1();
      break;
    case 2:
      menu.SetupMenu();
      break;
    case 3:
      menu.DateTime();
      break;
    case 4:
      menu.Cooling();
      break;
    case 5:
      menu.Heating();
      break;
    case 6:
      menu.Lighting();
      break;
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
      menu.Watering();
      break;
    }
  }
  if (enc.click())
  {
    if (enc.counter == 2)
      menu.SetupMenuSet();
    if (enc.counter == 3)
      menu.DateTimeSet();
    if (enc.counter == 4)
      menu.CoolingSet();
    if (enc.counter == 5)
      menu.HeatingSet();
    if (enc.counter == 6)
      menu.LightingSet();
    if ((enc.counter >= 7) and (enc.counter < 14))
      menu.WateringSet();
  }
}