#include <data.h>

extern PCF8574 portPoliv;
extern DS3231 rtc;
elapsedSeconds timePoliv;

bool q[8]{};
uint8_t setLong[8]{0, EEPROM.read(EE_VLV_1_SET_LONG), EEPROM.read(EE_VLV_2_SET_LONG), EEPROM.read(EE_VLV_3_SET_LONG), EEPROM.read(EE_VLV_4_SET_LONG), EEPROM.read(EE_VLV_5_SET_LONG), EEPROM.read(EE_VLV_6_SET_LONG), EEPROM.read(EE_VLV_7_SET_LONG)};
IO_PORT vlv[8]{POMP, VLV_1, VLV_2, VLV_3, VLV_4, VLV_5, VLV_6, VLV_7};
uint8_t i = constrain(i, 1, 8);

void Func::SetPoliv()
{
    uint8_t startHour = EEPROM.read(EE_SET_HOUR);
    uint8_t startMinute = EEPROM.read(EE_SET_MINUTE);
    uint8_t setWeekDay = EEPROM.read(EE_SET_WEEK_DAY);

    q[1] = bitRead(EEPROM.read(EE_VLV_1_SET_WEEK_DAYS), (rtc.getWeekDay()) - 1);
    q[2] = bitRead(EEPROM.read(EE_VLV_2_SET_WEEK_DAYS), (rtc.getWeekDay()) - 1);
    q[3] = bitRead(EEPROM.read(EE_VLV_3_SET_WEEK_DAYS), (rtc.getWeekDay()) - 1);
    q[4] = bitRead(EEPROM.read(EE_VLV_4_SET_WEEK_DAYS), (rtc.getWeekDay()) - 1);
    q[5] = bitRead(EEPROM.read(EE_VLV_5_SET_WEEK_DAYS), (rtc.getWeekDay()) - 1);
    q[6] = bitRead(EEPROM.read(EE_VLV_6_SET_WEEK_DAYS), (rtc.getWeekDay()) - 1);
    q[7] = bitRead(EEPROM.read(EE_VLV_7_SET_WEEK_DAYS), (rtc.getWeekDay()) - 1);

    if (rtc.getHour() >= startHour && rtc.getMinute() >= startMinute && setWeekDay != rtc.getWeekDay())
    {
        if (q[i])
        {
            portPoliv.setBit(POMP, true);
            portPoliv.setBit(vlv[i], true);
            if (timePoliv >= setLong[i] * 60)
            {
                portPoliv.setRegister(0);
                timePoliv = 0;
                i++;
            }
        }
        else
            i++;
        if (i > 7)
        {
            setWeekDay = rtc.getWeekDay();
            EEPROM.put(EE_SET_WEEK_DAY, setWeekDay);
            i = 1;
        }
    }
}
