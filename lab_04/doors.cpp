#include "doors.h"

Doors::Doors(QObject *parent):
    QObject(parent),
    state(DOORS_CLOSED)
{
    open_doors_timer.setSingleShot(true);
    close_doors_timer.setSingleShot(true);
    wait_doors_timer.setSingleShot(true);

    QObject::connect(&open_doors_timer, &QTimer::timeout, this, &Doors::opened_doors_slot);
    QObject::connect(&close_doors_timer, &QTimer::timeout, this, &Doors::closed_doors_slot);
    QObject::connect(&wait_doors_timer, &QTimer::timeout, this, &Doors::close_doors_slot);
}

void Doors::open_doors_slot()
{
    if (state != DOORS_CLOSED && state != DOORS_CLOSING)
        return;

    qInfo("[Двери] Двери открываются");

    if (state == DOORS_CLOSED)
        open_doors_timer.start(OPEN_DOORS_TIME);
    else if (state == DOORS_CLOSING)
    {
        int cur_close_time = close_doors_timer.remainingTime();
        int opening_time = (cur_close_time * OPEN_DOORS_TIME) / CLOSE_DOORS_TIME;

        open_doors_timer.start(opening_time);
        close_doors_timer.stop();
    }

    state = DOORS_OPENING;
}

void Doors::close_doors_slot()
{
    if (state != DOORS_OPENED)
        return;

    qInfo("[Двери] Двери закрываются");

    state = DOORS_CLOSING;
    close_doors_timer.start(CLOSE_DOORS_TIME);
}

void Doors::opened_doors_slot()
{
    if (state != DOORS_OPENING)
        return;

    state = DOORS_OPENED;

    qInfo("[Двери] Двери открыты");

    wait_doors_timer.start(WAIT_DOORS_TIME);
}

void Doors::closed_doors_slot()
{
    if (state != DOORS_CLOSING)
        return;

    state = DOORS_CLOSED;

    qInfo("[Двери] Двери закрыты");

    emit doors_is_closed_signal();
}
