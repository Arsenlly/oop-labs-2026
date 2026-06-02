#ifndef CAMERAVIEWADAPTER_H
#define CAMERAVIEWADAPTER_H

#include "basecamera.h"

#include <eigen3/Eigen/Dense>
#include <memory>

class CameraProjAdapter
{
public:
    CameraProjAdapter() = delete;
    CameraProjAdapter(std::shared_ptr<BaseCamera> camera);

    Eigen::Matrix4d getViewMatrix();

private:
    std::shared_ptr<BaseCamera> _camera;
};

#endif // CAMERAVIEWADAPTER_H
