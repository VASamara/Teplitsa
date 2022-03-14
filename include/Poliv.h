#ifndef _POLIV_H
#define _POLIV_H
#include <data.h>

class Poliv
{
private:
    enum WeekDay : uint8_t
    {
        MO = 1 << 0,
        TU = 1 << 1,
        WE = 1 << 2,
        TH = 1 << 3,
        FR = 1 << 4,
        SA = 1 << 5,
        SU = 1 << 6,
        PUST = 1 << 7
    };

public:
    void SetPoliv();
};

#endif