#include <Poliv.h>

extern PCF8574 portPoliv;
extern DS3231 rtc;


void Poliv::SetPoliv(IO_PORT)
{

    uint8_t SetWeekDays;
    uint8_t SetHours = constrain(SetHours, 0, 23);
    uint8_t SetMinutes = constrain(SetMinutes, 0, 59);
    uint8_t SetLong = constrain(SetLong, 0, 59);
    static IO_PORT bitValve;
    switch (bitValve)
    {
    case VLV_1:
        SetWeekDays = EEPROM.read(EE_VLV_1_SET_WEEK_DAYS);
        SetHours = EEPROM.read(EE_VLV_1_SET_HOUR);
        SetMinutes = EEPROM.read(EE_VLV_1_SET_MINUTE);
        SetLong = EEPROM.read(EE_VLV_1_SET_LONG);
        break;
    case VLV_2:
        SetWeekDays = EEPROM.read(EE_VLV_2_SET_WEEK_DAYS);
        SetHours = EEPROM.read(EE_VLV_2_SET_HOUR);
        SetMinutes = EEPROM.read(EE_VLV_2_SET_MINUTE);
        SetLong = EEPROM.read(EE_VLV_2_SET_LONG);
        break;
    case VLV_3:
        SetWeekDays = EEPROM.read(EE_VLV_3_SET_WEEK_DAYS);
        SetHours = EEPROM.read(EE_VLV_3_SET_HOUR);
        SetMinutes = EEPROM.read(EE_VLV_3_SET_MINUTE);
        SetLong = EEPROM.read(EE_VLV_3_SET_LONG);
        break;
    case VLV_4:
        SetWeekDays = EEPROM.read(EE_VLV_4_SET_WEEK_DAYS);
        SetHours = EEPROM.read(EE_VLV_4_SET_HOUR);
        SetMinutes = EEPROM.read(EE_VLV_4_SET_MINUTE);
        SetLong = EEPROM.read(EE_VLV_4_SET_LONG);
        break;
    case VLV_5:
        SetWeekDays = EEPROM.read(EE_VLV_5_SET_WEEK_DAYS);
        SetHours = EEPROM.read(EE_VLV_5_SET_HOUR);
        SetMinutes = EEPROM.read(EE_VLV_5_SET_MINUTE);
        SetLong = EEPROM.read(EE_VLV_5_SET_LONG);
        break;
    case VLV_6:
        SetWeekDays = EEPROM.read(EE_VLV_6_SET_WEEK_DAYS);
        SetHours = EEPROM.read(EE_VLV_6_SET_HOUR);
        SetMinutes = EEPROM.read(EE_VLV_6_SET_MINUTE);
        SetLong = EEPROM.read(EE_VLV_6_SET_LONG);
        break;
    case VLV_7:
        SetWeekDays = EEPROM.read(EE_VLV_7_SET_WEEK_DAYS);
        SetHours = EEPROM.read(EE_VLV_7_SET_HOUR);
        SetMinutes = EEPROM.read(EE_VLV_7_SET_MINUTE);
        SetLong = EEPROM.read(EE_VLV_7_SET_LONG);
        break;
    }
    static bool start;
    switch (rtc.getWeekDay())
    {
    case 1:
        start = (MO | SetWeekDays);
        break;
    case 2:
        start = (TU | SetWeekDays);
        break;
    case 3:
        start = (WE | SetWeekDays);
        break;
    case 4:
        start = (TH | SetWeekDays);
        break;
    case 5:
        start = (FR | SetWeekDays);
        break;
    case 6:
        start = (SA | SetWeekDays);
        break;
    case 7:
        start = (SU | SetWeekDays);
        break;
    }

    if ((SetHours == rtc.getHour()) && (SetMinutes >= rtc.getMinute()) && (start == true) && (SetLong != 0))
    {
        elapsedSeconds timePoliv;
        portPoliv.setBit(POMP, true);
        portPoliv.setBit(bitValve, true);
        // timePoliv = 0;
        if (timePoliv >= (SetLong * 60))
        {
            portPoliv.setRegister(0);
            timePoliv = 0;
        }
    }
}
