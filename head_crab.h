#ifndef HEAD_CRAB_H_INCLUDED
#define HEAD_CRAB_H_INCLUDED

#include <stdbool.h>

#define RACE 4                // number of flights
#define PLC  12               // number of seats to plane
#define LIM  20               // passenger name size limit
#define DATAFILE  "C:\\database.dat"

struct elysium
{
    char fname[LIM];
    char lname[LIM];
};

struct disco
{
    int place;
    bool ready;
    struct elysium revashol;
};

#endif // HEAD_CRAB_H_INCLUDED
