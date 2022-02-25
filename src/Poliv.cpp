#include <Poliv.h>

void Poliv::SetPoliv(uint8_t valve)
{
    valve = constrain(valve, 1, 7);
    uint8_t SetWeekDay1;
    uint8_t SetWeekDay2;
    uint8_t SetHours1 = constrain(SetHours1, 0, 23);
    uint8_t SetHours2 = constrain(SetHours2, 0, 23);
    uint8_t SetMinutes1 = constrain(SetMinutes1, 0, 59);
    uint8_t SetMinutes2 = constrain(SetMinutes2, 0, 59);
    uint8_t SetLong1 = constrain(SetLong1, 0, 99);
    uint8_t SetLong2 = constrain(SetLong2, 0, 99);
}