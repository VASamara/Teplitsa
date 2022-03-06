#ifndef _MENU_H
#define _MENU_H
#include <data.h>

// extern AHT10 aht10;
// extern DS3231 rtc;
// extern LiquidCrystal_I2C lcd;
// extern EncButton<EB_TICK, 2, 3, 4> enc;
//  extern PCF8574 portPoliv;

class MenuLCD
{
public:
    void MainMenu();
    void MainMenu1();
    void DateTime();
    void DateTimeSet();
    void Lighting();
    void LightingSet();
    void Heating();
    void HeatingSet();
    void Cooling();
    void CoolingSet();
    void Watering();
    void WateringSet();
    void SetupMenu();
    void SetupMenuSet();
};

#endif