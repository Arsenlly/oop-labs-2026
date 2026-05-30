#ifndef DEFINES_H
#define DEFINES_H

#define N_FLOOR 12
#define N_ELEVATOR 1

#define OPEN_DOORS_TIME 1000
#define CLOSE_DOORS_TIME 1000
#define WAIT_DOORS_TIME 1000

#define MOVING_TIME 1000

enum dir_t
{
    DIR_DOWN = 0,
    DIR_STAND,
    DIR_UP
};

enum floor_order_t
{
    FLOOR_ORDER_UP = 0,
    FLOOR_ORDER_DOWN,
    FLOOR_ORDER_BOTH,
    FLOOR_ORDER_NONE
};

#endif // DEFINES_H
