#include <Poliv.h>

extern PCF8574 portPoliv;
extern DS3231 rtc;
elapsedSeconds polivInt;
extern IO_PORT bitValve;
extern uint8_t numValve;
uint8_t SetWeekDays;
uint8_t SetHours;
uint8_t SetMinutes;
uint8_t SetLong;

void Poliv::SetPoliv()
{
    elapsedSeconds es;
    uint8_t startHour = EEPROM.read(EE_VLV_1_SET_HOUR);
    uint8_t startMinute = EEPROM.read(EE_VLV_1_SET_MINUTE);
    uint8_t q[7]{};
    bool vlv1 = bitRead(EEPROM.read(EE_VLV_1_SET_WEEK_DAYS), (rtc.getWeekDay()) - 1);
    bool vlv2 = bitRead(EEPROM.read(EE_VLV_2_SET_WEEK_DAYS), (rtc.getWeekDay()) - 1);
    bool vlv3 = bitRead(EEPROM.read(EE_VLV_3_SET_WEEK_DAYS), (rtc.getWeekDay()) - 1);
    bool vlv4 = bitRead(EEPROM.read(EE_VLV_4_SET_WEEK_DAYS), (rtc.getWeekDay()) - 1);
    bool vlv5 = bitRead(EEPROM.read(EE_VLV_5_SET_WEEK_DAYS), (rtc.getWeekDay()) - 1);
    bool vlv6 = bitRead(EEPROM.read(EE_VLV_6_SET_WEEK_DAYS), (rtc.getWeekDay()) - 1);
    bool vlv7 = bitRead(EEPROM.read(EE_VLV_7_SET_WEEK_DAYS), (rtc.getWeekDay()) - 1);

    if ((rtc.getHour() == startHour) && rtc.getMinute() >= startMinute)
    {
        if (vlv1)
            StartPoliv(VLV_1, EEPROM.read(EE_VLV_1_SET_LONG));
    }
}
void Poliv::StartPoliv(IO_PORT bitValve, uint8_t setLong)
{
    elapsedSeconds timePoliv;
    portPoliv.setBit(POMP, true);
    portPoliv.setBit(bitValve, true);
    Serial.println(bitValve);
    Serial.println(timePoliv);
    if (timePoliv >= (setLong))
    {
        portPoliv.setRegister(0);
        timePoliv = 0;
        return;
    }
}
/*
    if (polivInt >= 10)
    {
        polivInt = 0;

        switch (numValve)
        {
        case 1:
            bitValve = VLV_1;
            SetWeekDays = EEPROM.read(EE_VLV_1_SET_WEEK_DAYS);
            SetHours = EEPROM.read(EE_VLV_1_SET_HOUR);
            SetMinutes = EEPROM.read(EE_VLV_1_SET_MINUTE);
            SetLong = EEPROM.read(EE_VLV_1_SET_LONG);
            break;
        case 2:
            bitValve = VLV_2;
            SetWeekDays = EEPROM.read(EE_VLV_2_SET_WEEK_DAYS);
            SetHours = EEPROM.read(EE_VLV_2_SET_HOUR);
            SetMinutes = EEPROM.read(EE_VLV_2_SET_MINUTE);
            SetLong = EEPROM.read(EE_VLV_2_SET_LONG);
            break;
        case 3:
            bitValve = VLV_3;
            SetWeekDays = EEPROM.read(EE_VLV_3_SET_WEEK_DAYS);
            SetHours = EEPROM.read(EE_VLV_3_SET_HOUR);
            SetMinutes = EEPROM.read(EE_VLV_3_SET_MINUTE);
            SetLong = EEPROM.read(EE_VLV_3_SET_LONG);
            break;
        case 4:
            bitValve = VLV_4;
            SetWeekDays = EEPROM.read(EE_VLV_4_SET_WEEK_DAYS);
            SetHours = EEPROM.read(EE_VLV_4_SET_HOUR);
            SetMinutes = EEPROM.read(EE_VLV_4_SET_MINUTE);
            SetLong = EEPROM.read(EE_VLV_4_SET_LONG);
            break;
        case 5:
            bitValve = VLV_5;
            SetWeekDays = EEPROM.read(EE_VLV_5_SET_WEEK_DAYS);
            SetHours = EEPROM.read(EE_VLV_5_SET_HOUR);
            SetMinutes = EEPROM.read(EE_VLV_5_SET_MINUTE);
            SetLong = EEPROM.read(EE_VLV_5_SET_LONG);
            break;
        case 6:
            bitValve = VLV_6;
            SetWeekDays = EEPROM.read(EE_VLV_6_SET_WEEK_DAYS);
            SetHours = EEPROM.read(EE_VLV_6_SET_HOUR);
            SetMinutes = EEPROM.read(EE_VLV_6_SET_MINUTE);
            SetLong = EEPROM.read(EE_VLV_6_SET_LONG);
            break;
        case 7:
            bitValve = VLV_7;
            SetWeekDays = EEPROM.read(EE_VLV_7_SET_WEEK_DAYS);
            SetHours = EEPROM.read(EE_VLV_7_SET_HOUR);
            SetMinutes = EEPROM.read(EE_VLV_7_SET_MINUTE);
            SetLong = EEPROM.read(EE_VLV_7_SET_LONG);
            break;
        }
        (numValve == 7) ? (numValve = 1) : (numValve++);

        static bool start;
        switch (rtc.getWeekDay())
        {
        case 1:
            start = (MO & SetWeekDays);
            break;
        case 2:
            start = (TU & SetWeekDays);
            break;
        case 3:
            start = (WE & SetWeekDays);
            break;
        case 4:
            start = (TH & SetWeekDays);
            break;
        case 5:
            start = (FR & SetWeekDays);
            break;
        case 6:
            start = (SA & SetWeekDays);
            break;
        case 7:
            start = (SU & SetWeekDays);
            break;
        }
        Serial.print(numValve);
        Serial.print(SetLong);
        Serial.println(start);

        if ((rtc.getHour() == SetHours) && (rtc.getMinute() >= SetMinutes) && (start == true) && (SetLong != 0))
        {

            StartPoliv();
        }
    }
}
*/
