#include "liftcontroller.h"

#include <iostream>

LiftController::LiftController(QObject *parent):
    QObject(parent),
    floor_orders(N_FLOOR, FLOOR_ORDER_NONE),
    cabin_orders(N_FLOOR, false)
{
    state = CON_FREE;
    cur_floor = 0;
    cur_dir = DIR_STAND;

    QObject::connect(this, &LiftController::start_processing_signal, this, &LiftController::start_processing_slot);
    QObject::connect(this, &LiftController::start_moving_signal, this, &LiftController::start_moving_slot);
    QObject::connect(this, &LiftController::free_controller_signal, this, &LiftController::free_controller_slot);
    QObject::connect(this, &LiftController::start_boarding_signal, this, &LiftController::start_boarding_slot);

    QObject::connect(&cabin, &Cabin::cabin_arrived_floor_signal, this, &LiftController::start_processing_slot);
    QObject::connect(&cabin, &Cabin::cabin_ready_to_move_signal, this, &LiftController::start_processing_slot);

    QObject::connect(this, &LiftController::cabin_move_up_signal, &cabin, &Cabin::cabin_move_up_slot);
    QObject::connect(this, &LiftController::cabin_move_down_signal, &cabin, &Cabin::cabin_move_down_slot);
    QObject::connect(this, &LiftController::cabin_start_boarding_signal, &cabin, &Cabin::cabin_start_boarding_slot);
}

void LiftController::add_floor_order(size_t floor, dir_t dir)
{
    if (floor_orders[floor] == FLOOR_ORDER_NONE)
        floor_orders[floor] = (dir == DIR_UP) ? FLOOR_ORDER_UP : FLOOR_ORDER_DOWN;
    else
    {
        if (floor_orders[floor] == FLOOR_ORDER_DOWN && dir == DIR_UP)
            floor_orders[floor] = FLOOR_ORDER_BOTH;
        else if (floor_orders[floor] == FLOOR_ORDER_UP && dir == DIR_DOWN)
            floor_orders[floor] = FLOOR_ORDER_BOTH;
    }
}

void LiftController::add_cabin_order(size_t floor)
{
    cabin_orders[floor] = true;
}

void LiftController::remove_order_on_cur_floor()
{
    floor_orders[cur_floor] = FLOOR_ORDER_NONE;

    cabin_orders[cur_floor] = false;
}

int LiftController::find_next_target()
{
    if (cur_dir == DIR_STAND)
    {
        // qDebug() << "stand";

        if (cabin_orders[cur_floor] || floor_orders[cur_floor] != FLOOR_ORDER_NONE)
            return cur_floor;

        int len = N_FLOOR;
        int target = 0;

        for (int i = 0;i < N_FLOOR;i++)
        {
            if (cabin_orders[i] || floor_orders[i] != FLOOR_ORDER_NONE)
            {
                if (abs(i - static_cast<int>(cur_floor)) < len)
                {
                    len = abs(i - static_cast<int>(cur_floor));
                    target = i;
                }
            }
        }

        if (target == N_FLOOR)
            return -1;
        else
            return target;
    }
    else if (cur_dir == DIR_UP)
    {
        // qDebug() << "up";

        if (cabin_orders[cur_floor] || floor_orders[cur_floor] == FLOOR_ORDER_UP)
            return cur_floor;

        for (int i = cur_floor + 1;i < N_FLOOR;i++)
        {
            if (cabin_orders[i] || floor_orders[i] == FLOOR_ORDER_UP || floor_orders[i] == FLOOR_ORDER_BOTH)
                return i;
        }

        // for (int i = cur_floor - 1;i >= 0;i--)
        // {
        //     if (cabin_orders[i] || floor_orders[i] != FLOOR_ORDER_NONE)
        //         return i;
        // }

        int farthestUp = -1;
        for (int i = cur_floor; i < N_FLOOR; i++)
        {
            if (cabin_orders[i] || floor_orders[i] != FLOOR_ORDER_NONE)
            {
                farthestUp = i;
            }
        }

        if (farthestUp != -1)
            return farthestUp;

        for (int i = cur_floor - 1; i >= 0; i--)
        {
            if (cabin_orders[i] || floor_orders[i] != FLOOR_ORDER_NONE)
                return i;
        }
    }
    else if (cur_dir == DIR_DOWN)
    {
        // qDebug() << "down";

        if (cabin_orders[cur_floor] || floor_orders[cur_floor] == FLOOR_ORDER_DOWN)
            return cur_floor;

        for (int i = cur_floor - 1;i >= 0;i--)
        {
            if (cabin_orders[i] || floor_orders[i] == FLOOR_ORDER_DOWN || floor_orders[i] == FLOOR_ORDER_BOTH)
                return i;
        }

        // for (int i = cur_floor + 1;i < N_FLOOR;i++)
        // {
        //     if (cabin_orders[i] || floor_orders[i] != FLOOR_ORDER_NONE)
        //         return i;
        // }

        int farthestDown = -1;
        for (int i = cur_floor; i >= 0; i--)
        {
            if (cabin_orders[i] || floor_orders[i] != FLOOR_ORDER_NONE)
            {
                farthestDown = i;
            }
        }

        if (farthestDown != -1)
            return farthestDown;

        for (int i = cur_floor + 1; i < N_FLOOR; i++)
        {
            if (cabin_orders[i] || floor_orders[i] != FLOOR_ORDER_NONE)
                return i;
        }
    }

    return -1;
}

void LiftController::call_floor_lift(size_t n_floor, dir_t dir)
{
    add_floor_order(n_floor - 1, dir);

    emit floor_button_change_signal(n_floor, dir, true);

    if (state == CON_FREE)
    {
        emit start_processing_signal(cur_floor);
    }
}

void LiftController::call_cabin_lift(size_t n_floor)
{
    add_cabin_order(n_floor - 1);

    emit cabin_button_change_signal(n_floor, true);

    if (state == CON_FREE)
    {
        emit start_processing_signal(cur_floor);
    }
}

void LiftController::start_processing_slot(size_t floor)
{
    if (state != CON_FREE && state != CON_MOVING && state != CON_BOARDING)
        return;

    qDebug() << "[Контроллер] Поиск следующей цели, лифт сейчас на" << cur_floor + 1 << "этаже";

    state = CON_PROC;

    cur_floor = floor;

    emit cabin_pos_change_signal(cur_floor + 1);

    int next_target = find_next_target();

    qDebug() << "[Контроллер] Следующая цель:" << next_target;

    if (next_target == -1)
    {
        cur_dir = DIR_STAND;
        emit free_controller_signal();
    }
    else if (next_target == cur_floor)
        emit start_boarding_signal();
    else
    {
        if (next_target > cur_floor)
            cur_dir = DIR_UP;
        else if (next_target < cur_floor)
            cur_dir = DIR_DOWN;

        emit start_moving_signal();
    }
}

void LiftController::start_moving_slot()
{
    if (state != CON_PROC)
        return;

    qDebug() << "[Контроллер] Начинается движение";

    state = CON_MOVING;

    if (cur_dir == DIR_UP)
    {
        emit cabin_move_up_signal();
    }
    else if (cur_dir == DIR_DOWN)
    {
        emit cabin_move_down_signal();
    }
}

void LiftController::free_controller_slot()
{
    if (state != CON_PROC)
        return;

    qDebug() << "[Контроллер] Заявок нет, контроллер свободен";

    state = CON_FREE;
}

void LiftController::start_boarding_slot()
{
    if (state != CON_PROC)
        return;

    qDebug() << "[Контроллер] Начинается посадка";

    state = CON_BOARDING;

    remove_order_on_cur_floor();
    emit cabin_button_change_signal(cur_floor + 1, false);
    emit floor_button_change_signal(cur_floor + 1, DIR_UP, false);
    emit floor_button_change_signal(cur_floor + 1, DIR_DOWN, false);

    emit cabin_start_boarding_signal();
}
