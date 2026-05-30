#ifndef CABIN_H
#define CABIN_H

#include "doors.h"
#include "defines.h"

#include <QObject>
#include <QTimer>
#include <QDebug>

class Cabin: public QObject
{
    Q_OBJECT

public:
    Cabin(QObject *parent = nullptr);

signals:
    void cabin_arrived_floor_signal(size_t floor);
    void cabin_ready_to_move_signal(size_t floor);

    void cabin_open_doors_signal();

public slots:
    void cabin_move_up_slot();
    void cabin_move_down_slot();
    void cabin_arrived_floor_slot();
    void cabin_start_boarding_slot();

private slots:
    void cabin_doors_closed_slot();

private:
    enum cabin_state_t
    {
        CABIN_READY_TO_MOVE = 0,
        CABIN_BOARDING,
        CABIN_ARRIVED,
        CABIN_MOVE_UP,
        CABIN_MOVE_DOWN
    };

    cabin_state_t state;

    Doors cabin_doors;

    size_t cur_floor;

    QTimer moving_timer;
};

#endif // CABIN_H
