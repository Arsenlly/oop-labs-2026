#ifndef PROJECTIONCAMERAACTION_H
#define PROJECTIONCAMERAACTION_H

#include "transformaction.h"
#include "moveaction.h"
#include "camera.h"

#include <memory>

class ProjectionCameraAction: public TransformAction
{
public:
    ProjectionCameraAction() = delete;
    ProjectionCameraAction(std::shared_ptr<Camera> camera);

    virtual ~ProjectionCameraAction() override = default;
};

#endif // PROJECTIONCAMERAACTION_H
