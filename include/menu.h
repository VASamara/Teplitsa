#ifndef _MENU_H
#define _MENU_H
#include <data.h>

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