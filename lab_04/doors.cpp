#include "doors.h"

Doors::Doors(QObject *parent):
    QObject(parent),
    state(DOORS_CLOSED)
{
    open_doors_timer.setSingleShot(true);
    close_doors_timer.setSingleShot(true);

    QObject:connect(&open_doors_timer, &QTimer::timeout, this, &Doors::opened_doors_slot);
    QObject:connect(&close_doors_timer, &QTimer::timeout, this, &Doors::closed_doors_slot);
}

void Doors::open_doors_slot()
{
    if (state != DOORS_CLOSED && state != DOORS_CLOSING)
        return;

    if (state == DOORS_CLOSED)
    {
        state = DOORS_OPENING;
        open_doors_timer.start(OPEN_DOORS_TIME);
    }
    else if (state == DOORS_CLOSING)
    {
        int cur_close_time = close_doors_timer.remainingTime();
        int opening_time = (cur_close_time / CLOSE_DOORS_TIME) * OPEN_DOORS_TIME;

        state = DOORS_OPENING;
        open_doors_timer.start(opening_time);
    }
}

void Doors::close_doors_slot()
{
    if (state != DOORS_OPENED)
        return;

    state = DOORS_CLOSING;
    close_doors_timer.start(CLOSE_DOORS_TIME);
}

void Doors::opened_doors_slot()
{
    state = DOORS_OPENED;
    emit doors_is_opened_signal();
}

void Doors::closed_doors_slot()
{
    state = DOORS_CLOSED;
    emit doors_is_closed_signal();
}
