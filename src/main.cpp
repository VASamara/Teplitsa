#include <data.h>

MenuLCD menu;
LiquidCrystal_I2C lcd(0x27, 20, 4);
EncButton<EB_TICK, 3, 2, 0> enc;
PCF8574 portPoliv;
AHT10 aht10;
DS3231 rtc;
Func func;
MicroDS18B20<DALLAS_1> ds;
GyverNTC tr1(0, 10100, 3950);
elapsedSeconds timeBackLight;
elapsedMillis ttr;
// File file;

void setup()
{
  pinMode(LIGHT, OUTPUT);
  pinMode(HEAT, OUTPUT);
  // pinMode(SPI_SS, OUTPUT);
  pinMode(DRV_PWM, OUTPUT);
  pinMode(DRV_SIG_1, OUTPUT);
  pinMode(DRV_SIG_2, OUTPUT);
  digitalWrite(DRV_SIG_1, LOW);
  digitalWrite(DRV_SIG_2, HIGH);
  elapsedSeconds sd;
  analogWrite(DRV_PWM, EEPROM.read(EE_COOLING_PWM));
  if (sd > 15)
    analogWrite(DRV_PWM, 0);
  lcd.init();
  lcd.backlight();
  timeBackLight = 0;
  Serial.begin(115200);
  portPoliv.setRegister(0);
  enc.getState();
  menu.MainMenu();
  // SD.begin(SPI_SS);
}
void loop()
{
  if (ttr >= 1000)
  {
    ttr = 0;
    Serial.print("Temperature ");
    Serial.print(tr1.getTempAverage());
    Serial.println(" *C");
  }
  if (bitRead(EEPROM.read(EE_OPTION_ON), 0))
    func.Cooling();
  if (bitRead(EEPROM.read(EE_OPTION_ON), 1))
    // func.Logging();
    func.Heating();
  if (bitRead(EEPROM.read(EE_OPTION_ON), 2))
    func.SetPoliv();
  if (bitRead(EEPROM.read(EE_OPTION_ON), 3))
    func.Lighting();

  enc.tick();
  if (enc.held())
    func.ButCooling();

  if (enc.right() or enc.left())
  {
    lcd.backlight();
    timeBackLight = 0;
    enc.counter = constrain(enc.counter, 0, 13);

    switch (enc.counter)
    {
    case 0:
      menu.MainMenu();
      break;
    case 1:
      menu.SetupMenu();
      break;
    case 2:
      menu.DateTime();
      break;
    case 3:
      menu.Cooling();
      break;
    case 4:
      menu.Heating();
      break;
    case 5:
      menu.Lighting();
      break;
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
      menu.Watering();
      break;
    }
  }
  if (enc.click())
  {
    lcd.backlight();
    timeBackLight = 0;
    if (enc.counter == 1)
      menu.SetupMenuSet();
    if (enc.counter == 2)
      menu.DateTimeSet();
    if (enc.counter == 3)
      menu.CoolingSet();
    if (enc.counter == 4)
      menu.HeatingSet();
    if (enc.counter == 5)
      menu.LightingSet();
    if ((enc.counter >= 6) and (enc.counter < 13))
      menu.WateringSet();
  }
  if (timeBackLight >= 300)
    lcd.noBacklight();
}