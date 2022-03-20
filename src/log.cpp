#include <data.h>

extern DS3231 rtc;
extern File file;
extern AHT10 aht10;

void Func::Logging(){
    
        String data = "";
        if (rtc.getHour() < 10)
            data += '0';
        data += rtc.getHour();
        data += ':';
        if (rtc.getMinute() < 10)
            data += '0';
        data += rtc.getMinute();
        data += ':';
        if (rtc.getSecond() < 10)
            data += '0';
        data += rtc.getSecond();
        data += '\t';
        data += aht10.getTemperature();
        data += '\t';
        data += aht10.getHumidity();
        data += '\t';
        data += aht10.getTemperature();
        data += '\t';
        data += aht10.getHumidity();

        String m[]{"n", "Jan", "Feb", "Mart", "Apr", "May", "June", "July", "Aug", "Sep", "Okt", "Nov", "Dec"};
        String month = "";
        if (uint8_t i = rtc.getMonth())
            month += m[i];

        if (!SD.mkdir(month))
            SD.mkdir(month);

        String fileName = month;
        fileName += "/Day";
        if (rtc.getDay() < 10)
            fileName += '0';
        fileName += rtc.getDay();
        fileName += ".csv";
/*
        Serial.println(month);
        Serial.println(fileName);
        Serial.println(data);
        file = SD.open(fileName, FILE_WRITE);
        file.println("data");
        file.close();
        
            file = SD.open(fileName);
            if (file)
            {
                Serial.println(fileName);

                // read from the file until there's nothing else in it:
                while (file.available())
                {
                    Serial.write(file.read());
                }
                // close the file:
                file.close();
            }
            else
            {
                // if the file didn't open, print an error:
                Serial.println("error opening fileName");

            }
            
 */          
}
