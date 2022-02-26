#ifndef Poliv_h
#define Poliv_h
#include <data.h>

extern PCF8574 portPoliv;
elapsedSeconds timePoliv;

class Poliv
{
private:
    /* data */
public:
    void SetPoliv(uint8_t valve, uint8_t number);
};

#endif