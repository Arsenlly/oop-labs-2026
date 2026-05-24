#ifndef ELEVATORSYSTEM_H
#define ELEVATORSYSTEM_H

#include <QObject>

#include "liftcontroller.h"
#include "defines.h"

class ElevatorSystem: public QObject
{
    Q_OBJECT

public:
    explicit ElevatorSystem(QObject *parent = nullptr);

signals:
    void floor_button_change_signal(size_t n_floor, dir_t dir, bool active_fl);
    void cabin_button_change_signal(size_t id_cabin, size_t n_floor, bool active_fl);

    void call_floor_lift_signal(size_t n_floor, dir_t dir);
    void call_cabin_lift_signal(size_t id_cabin, size_t n_floor);

public slots:
    void call_floor_lift_slot(size_t n_floor, dir_t dir);
    void call_cabin_lift_slot(size_t id_cabin, size_t n_floor);

    void floor_button_change_slot(size_t n_floor, dir_t dir, bool active_fl);
    void cabin_button_change_slot(size_t id_cabin, size_t n_floor, bool active_fl);

private:
    LiftController _controller;
};

#endif // ELEVATORSYSTEM_H
