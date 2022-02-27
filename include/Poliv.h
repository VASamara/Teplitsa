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
        PUST = 1 << 7,
        MO = 1 << 0,
        TU = 1 << 1,
        WE = 1 << 2,
        TH = 1 << 3,
        FR = 1 << 4,
        SA = 1 << 5,
        SU = 1 << 6
    };
    void SetPoliv(IO_PORT);
};

#endif