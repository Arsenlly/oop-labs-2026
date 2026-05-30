#include "cabin.h"

Cabin::Cabin(QObject *parent):
    QObject(parent),
    state(CABIN_READY_TO_MOVE)
{
    cur_floor = 0;

    moving_timer.setSingleShot(true);

    QObject::connect(this, &Cabin::cabin_open_doors_signal, &cabin_doors, &Doors::open_doors_slot);

    QObject::connect(&cabin_doors, &Doors::doors_is_closed_signal, this, &Cabin::cabin_doors_closed_slot);

    QObject::connect(&moving_timer, &QTimer::timeout, this, &Cabin::cabin_arrived_floor_slot);
}

void Cabin::cabin_move_up_slot()
{
    if (state != CABIN_READY_TO_MOVE && state != CABIN_ARRIVED)
        return;

    qDebug() << "[Кабина] Кабина движется вверх";

    cur_floor++;
    moving_timer.start(MOVING_TIME);

    state = CABIN_MOVE_UP;
}

void Cabin::cabin_move_down_slot()
{
    if (state != CABIN_READY_TO_MOVE && state != CABIN_ARRIVED)
        return;

    qDebug() << "[Кабина] Кабина движется вниз";

    cur_floor--;
    moving_timer.start(MOVING_TIME);

    state = CABIN_MOVE_DOWN;
}

void Cabin::cabin_arrived_floor_slot()
{
    if (state != CABIN_MOVE_UP && state != CABIN_MOVE_DOWN)
        return;

    qDebug() << "[Кабина] Кабина прибыла на " << cur_floor + 1 << "этаж";

    state = CABIN_ARRIVED;

    emit cabin_arrived_floor_signal(cur_floor);
}

void Cabin::cabin_start_boarding_slot()
{
    if (state != CABIN_ARRIVED && state != CABIN_READY_TO_MOVE)
        return;

    qDebug() << "[Кабина] Начинается посадка в кабину";

    state = CABIN_BOARDING;

    emit cabin_open_doors_signal();
}

void Cabin::cabin_doors_closed_slot()
{
    if (state != CABIN_BOARDING)
        return;

    qDebug() << "[Кабина] Кабина готова к движению";

    state = CABIN_READY_TO_MOVE;

    emit cabin_ready_to_move_signal(cur_floor);
}
