#include "transformmanager.h"

void TransformManager::ScaleObject(std::shared_ptr<Object> object, double kx, double ky, double kz)
{
    ScaleAction action(kx, ky, kz);

    TransformVisitor visitor(action);

    object->accept(visitor);
}

void TransformManager::MoveObject(std::shared_ptr<Object> object, double dx, double dy, double dz)
{
    MoveAction action(dx, dy, dz);

    TransformVisitor visitor(action);

    object->accept(visitor);
}

void TransformManager::RotateObject(std::shared_ptr<Object> object, double x_angle, double y_angle, double z_angle)
{
    RotateAction action(x_angle, y_angle, z_angle);

    TransformVisitor visitor(action);

    object->accept(visitor);
}
