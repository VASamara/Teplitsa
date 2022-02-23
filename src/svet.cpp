#include "svet.h"
#include "data.h"
#include <elapsedMillis.h>

// uint16_t interval =5;

void Dimmer::rassvet()
{
    pinMode(LIGHT, OUTPUT);

    for (uint8_t start = 0; start < 255;)
    {

        if (eSeconds >= interval)
        {
            eSeconds = 0;
            start++;
            analogWrite(LIGHT, start);
        }
    }
}
void Dimmer::zakat()
{
    pinMode(LIGHT, OUTPUT);

    for (uint8_t start = 255; start > 0;)
    {

        if (eSeconds >= interval)
        {
            eSeconds = 0;
            start--;
            analogWrite(LIGHT, start);
        }
    }
}
