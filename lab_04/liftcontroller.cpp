#include "liftcontroller.h"

LiftController::LiftController(QObject *parent): QObject(parent)
{
    for (size_t i = 0;i < N_ELEVATOR;i++)
    {
        cabins.push_back(std::make_unique<Cabin>());
    }
}

void LiftController::call_floor_lift_slot(size_t n_floor, dir_t dir)
{

}

void LiftController::call_cabin_lift_slot(size_t id_cabin, size_t n_floor)
{

}
