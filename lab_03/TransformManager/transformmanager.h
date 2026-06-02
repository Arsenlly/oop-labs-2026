#ifndef TRANSFORMMANAGER_H
#define TRANSFORMMANAGER_H

#include "object.h"
#include "transformvisitor.h"
#include "scaleaction.h"
#include "moveaction.h"
#include "rotateaction.h"
#include "scenemanager.h"
#include "point.h"

#include <memory>

class TransformManager
{
    public:
    TransformManager() = default;
    ~TransformManager() = default;

    void ScaleObject(std::shared_ptr<SceneManager> scene_manager, size_t id, Point &center, double kx, double ky, double kz);
    void MoveObject(std::shared_ptr<SceneManager> scene_manager, size_t id, double dx, double dy, double dz);
    void RotateObject(std::shared_ptr<SceneManager> scene_manager, size_t id, Point &center, double x_angle, double y_angle, double z_angle);
};

#endif // TRANSFORMMANAGER_H
