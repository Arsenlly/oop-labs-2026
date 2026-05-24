#ifndef DEFINES_H
#define DEFINES_H

#define N_FLOOR 12
#define N_ELEVATOR 2

#define OPEN_DOORS_TIME 1000
#define CLOSE_DOORS_TIME 1000

#define BOARDING_TIME 2000


enum dir_t
{
    DIR_DOWN = -1,
    DIR_STAND = 0,
    DIR_UP = 1
};

enum cabin_state_t
{
    CABIN_FREE = 0,
    CABIN_MOVE,
    CABIN_START_BOARDING,
    CABIN_FINISH_BOARDING
};

enum doors_state_t
{
    DOORS_OPENING = 0,
    DOORS_OPENED,
    DOORS_CLOSING,
    DOORS_CLOSED
};

#endif // DEFINES_H
