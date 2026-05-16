#include "rotatemodelcommand.h"

RotateModelCommand::RotateModelCommand(std::size_t id, double x_angle, double y_angle, double z_angle)
{
    _id = id;
    _x_angle = x_angle;
    _y_angle = y_angle;
    _z_angle = z_angle;
}

void RotateModelCommand::execute()
{
    // std::shared_ptr<Object> object = _sceneManager->getObject(_id);
    // _transformManager->RotateObject(object, _x_angle, _y_angle, _z_angle);
}
