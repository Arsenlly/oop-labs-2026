#include "projectioncameraaction.h"

ProjectionCameraAction::ProjectionCameraAction(std::shared_ptr<BaseCamera> camera)
{
    CameraProjAdapter camera_adapter(camera);
    Eigen::Matrix4d view_matrix = camera_adapter.getViewMatrix();

    transform_matrix = view_matrix;
}
