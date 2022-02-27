#include <Poliv.h>

extern PCF8574 portPoliv;
extern DS3231 rtc;
elapsedSeconds timePoliv;

void Poliv::SetPoliv(IO_PORT)
{

    uint8_t SetWeekDay;
    uint8_t SetHours = constrain(SetHours, 0, 23);
    uint8_t SetMinutes = constrain(SetMinutes, 0, 59);
    uint8_t SetLong = constrain(SetLong, 0, 59);
    static IO_PORT bitValve;
    switch (bitValve)
    {
    case VLV_1:
        SetWeekDay = EEPROM.read(16);
        SetHours = EEPROM.read(17);
        SetMinutes = EEPROM.read(18);
        SetLong = EEPROM.read(19);
        break;
    case VLV_2:
        SetWeekDay = EEPROM.read(20);
        SetHours = EEPROM.read(21);
        SetMinutes = EEPROM.read(22);
        SetLong = EEPROM.read(23);
        break;
    case VLV_3:
        SetWeekDay = EEPROM.read(24);
        SetHours = EEPROM.read(25);
        SetMinutes = EEPROM.read(26);
        SetLong = EEPROM.read(27);
        break;
    case VLV_4:
        SetWeekDay = EEPROM.read(28);
        SetHours = EEPROM.read(29);
        SetMinutes = EEPROM.read(30);
        SetLong = EEPROM.read(31);
        break;
    case VLV_5:
        SetWeekDay = EEPROM.read(32);
        SetHours = EEPROM.read(33);
        SetMinutes = EEPROM.read(34);
        SetLong = EEPROM.read(35);
        break;
    case VLV_6:
        SetWeekDay = EEPROM.read(36);
        SetHours = EEPROM.read(37);
        SetMinutes = EEPROM.read(38);
        SetLong = EEPROM.read(39);
        break;
    case VLV_7:
        SetWeekDay = EEPROM.read(40);
        SetHours = EEPROM.read(41);
        SetMinutes = EEPROM.read(42);
        SetLong = EEPROM.read(43);
        break;
    }

    if ((SetHours == rtc.getHour()) && (SetMinutes >= rtc.getMinute()) && (SetHours != 0) && (SetLong != 0))
    {
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
