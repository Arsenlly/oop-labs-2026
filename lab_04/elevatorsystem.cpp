#include "elevatorsystem.h"

ElevatorSystem::ElevatorSystem(QObject *parent): QObject(parent)
{
    QObject::connect(this, &ElevatorSystem::call_floor_lift_signal, &_controller, &LiftController::call_floor_lift_slot);
    QObject::connect(this, &ElevatorSystem::call_cabin_lift_signal, &_controller, &LiftController::call_cabin_lift_slot);

    QObject::connect(&_controller, &LiftController::floor_button_change_signal, this, &ElevatorSystem::floor_button_change_slot);
    QObject::connect(&_controller, &LiftController::cabin_button_change_signal, this, &ElevatorSystem::cabin_button_change_slot);
}

void ElevatorSystem::call_floor_lift_slot(size_t n_floor, dir_t dir)
{
    emit call_floor_lift_signal(n_floor, dir);
}

void ElevatorSystem::call_cabin_lift_slot(size_t id_cabin, size_t n_floor)
{
    emit call_cabin_lift_signal(id_cabin, n_floor);
}

void ElevatorSystem::floor_button_change_slot(size_t n_floor, dir_t dir, bool active_fl)
{
    emit floor_button_change_signal(n_floor, dir, active_fl);
}

void ElevatorSystem::cabin_button_change_slot(size_t id_cabin, size_t n_floor, bool active_fl)
{
    emit cabin_button_change_signal(id_cabin, n_floor, active_fl);
}
