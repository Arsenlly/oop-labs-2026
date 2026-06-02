#include "rotateobjectcommand.h"

RotateModelCommand::RotateModelCommand(std::size_t id, Point &center, double x_angle, double y_angle, double z_angle)
{
    _id = id;
    _center = center;
    _x_angle = x_angle;
    _y_angle = y_angle;
    _z_angle = z_angle;
}

void RotateModelCommand::execute()
{
    _transformManager->RotateObject(_sceneManager, _id, _center, _x_angle, _y_angle, _z_angle);
}
