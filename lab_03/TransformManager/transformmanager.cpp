#include "transformmanager.h"

void TransformManager::ScaleObject(std::shared_ptr<SceneManager> scene_manager, size_t id, Point &center, double kx, double ky, double kz)
{
    std::shared_ptr<Object> object = scene_manager->getObject(id);

    ScaleAction action(center, kx, ky, kz);

    TransformVisitor visitor(action);

    object->accept(visitor);
}

void TransformManager::MoveObject(std::shared_ptr<SceneManager> scene_manager, size_t id, double dx, double dy, double dz)
{
    std::shared_ptr<Object> object = scene_manager->getObject(id);

    MoveAction action(dx, dy, dz);

    TransformVisitor visitor(action);

    object->accept(visitor);
}

void TransformManager::RotateObject(std::shared_ptr<SceneManager> scene_manager, size_t id, Point &center, double x_angle, double y_angle, double z_angle)
{
    std::shared_ptr<Object> object = scene_manager->getObject(id);

    RotateAction action(center, x_angle, y_angle, z_angle);

    TransformVisitor visitor(action);

    object->accept(visitor);
}
