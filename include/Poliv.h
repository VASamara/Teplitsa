#ifndef _POLIV_H
#define _POLIV_H
#include <data.h>



class Poliv
{
private:
    /* data */
public:
    enum WeekDay : uint8_t

    {
        PUST = 1 << 0,
        MO = 1 << 1,
        TU = 1 << 2,
        WE = 1 << 3,
        TH = 1 << 4,
        FR = 1 << 5,
        SA = 1 << 6,
        SU = 1 << 7
    };
    void SetPoliv(IO_PORT);
};

#endif