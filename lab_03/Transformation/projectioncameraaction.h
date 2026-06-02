#ifndef PROJECTIONCAMERAACTION_H
#define PROJECTIONCAMERAACTION_H

#include "transformaction.h"
#include "moveaction.h"
#include "basecamera.h"
#include "cameraviewadapter.h"

#include <memory>
#include <cmath>

class ProjectionCameraAction: public TransformAction
{
public:
    ProjectionCameraAction() = delete;
    ProjectionCameraAction(std::shared_ptr<BaseCamera> camera);

    virtual ~ProjectionCameraAction() override = default;
};

#endif // PROJECTIONCAMERAACTION_H
