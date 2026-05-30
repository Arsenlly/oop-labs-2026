#include "elevatorsystem.h"

#include <iostream>

ElevatorSystem::ElevatorSystem(QObject *parent): QObject(parent)
{
    QObject::connect(&_controller, &LiftController::floor_button_change_signal, this, &ElevatorSystem::floor_button_change_slot);
    QObject::connect(&_controller, &LiftController::cabin_button_change_signal, this, &ElevatorSystem::cabin_button_change_slot);
    QObject::connect(&_controller, &LiftController::cabin_pos_change_signal, this, &ElevatorSystem::cabin_pos_change_slot);
}

void ElevatorSystem::call_floor_lift_slot(size_t n_floor, dir_t dir)
{
    _controller.call_floor_lift(n_floor, dir);
}

void ElevatorSystem::call_cabin_lift_slot(size_t n_floor)
{
    _controller.call_cabin_lift(n_floor);
}

void ElevatorSystem::floor_button_change_slot(size_t n_floor, dir_t dir, bool active_fl)
{
    emit floor_button_change_signal(n_floor, dir, active_fl);
}

void ElevatorSystem::cabin_button_change_slot(size_t n_floor, bool active_fl)
{
    emit cabin_button_change_signal(n_floor, active_fl);
}

void ElevatorSystem::cabin_pos_change_slot(size_t n_floor)
{
    emit cabin_pos_change_signal(n_floor);
}
