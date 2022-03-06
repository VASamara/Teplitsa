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
uint8_t numValve;

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
  menu.MainMenu();
}
void loop()
{
  enc.tick();
  if (enc.right() or enc.left())
  {
    enc.counter = constrain(enc.counter, 0, 7);
    Serial.println(enc.counter);
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
      menu.Watering();
      break;
    }
  }
  if (enc.click()) 
  {
    if (enc.counter == 2)
    {
      menu.SetupMenuSet();
      Serial.print(enc.counter);
    }
    // return;
    if (enc.counter == 3)
    {
      menu.DateTimeSet();
      Serial.print(enc.counter);
    }
    // return;
    if (enc.counter == 4)
    {
      menu.CoolingSet();
      Serial.print(enc.counter);
    }
    // return;
    if (enc.counter == 5)
    {
      menu.HeatingSet();
      Serial.print(enc.counter);
    }
    // return;
    if (enc.counter == 6)
    {
      menu.LightingSet();
      Serial.print(enc.counter);
    }
    // return;
    if (enc.counter == 7)
    {
      menu.WateringSet();
      Serial.print(enc.counter);
    }
  }
  // return;

/*
{
  while (1)
  {

    enc.tick();
    lcd.blink();
    uint8_t str[]{8, 8, 8, 8};
    uint8_t sim[]{0, 1, 2, 3};
    uint8_t i = constrain(i, 0, 3);
    if (enc.right())
      i++;
    if (enc.left())
      i--;
    lcd.setCursor(str[i], sim[i]);
    if (enc.click() && (i == 0))
    {
      if (EEPROM.read(EE_COOLING_ON) == 0)
      {
        EEPROM.write(EE_COOLING_ON, 1);
        lcd.print("On ");
        lcd.noBlink();
        return;
      }
      if (EEPROM.read(EE_COOLING_ON) == 1)
      {
        EEPROM.write(EE_COOLING_ON, 0);
        lcd.print("Off");
        lcd.noBlink();
        return;
      }
    }
  }
}*/
}