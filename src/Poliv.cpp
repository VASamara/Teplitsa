#include <Poliv.h>

void Poliv::SetPoliv(uint8_t valve, uint8_t number)
{
    valve = constrain(valve, 1, 7);
    number = constrain(number, 1, 2);

    // uint8_t SetWeekDay1;
    uint8_t SetWeekDay;
    // uint8_t SetHours1 = constrain(SetHours1, 0, 23);
    uint8_t SetHours = constrain(SetHours, 0, 23);
    // uint8_t SetMinutes1 = constrain(SetMinutes1, 0, 59);
    uint8_t SetMinutes = constrain(SetMinutes, 0, 59);
    // uint8_t SetLong1 = constrain(SetLong1, 0, 99);
    uint8_t SetLong = constrain(SetLong, 0, 99);

    if ((SetHours == rtc.getHour()) && (SetMinutes == rtc.getMinute()))
    {
        portPoliv.setBit(0, true);
        portPoliv.setBit(valve, true);
        // timePoliv = 0;
        if (timePoliv >= (SetLong * 60))
        {
            portPoliv.setRegister(0);
            timePoliv = 0;
        }
    }
}
