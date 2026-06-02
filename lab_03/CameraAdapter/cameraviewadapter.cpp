#include "cameraviewadapter.h"

CameraProjAdapter::CameraProjAdapter(std::shared_ptr<BaseCamera> camera): _camera(camera) {}

Eigen::Matrix4d CameraProjAdapter::getViewMatrix()
{
    auto structure = _camera->_structure;

    return structure->getViewMatrix();
}
