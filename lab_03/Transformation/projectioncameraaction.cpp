#include "projectioncameraaction.h"

ProjectionCameraAction::ProjectionCameraAction(std::shared_ptr<Camera> camera)
{
    Eigen::Matrix4d rotate;

    rotate.setZero();

    rotate(0, 0) = camera->getRight().getX();
    rotate(0, 1) = camera->getRight().getY();
    rotate(0, 2) = camera->getRight().getZ();

    rotate(1, 0) = camera->getUp().getX();
    rotate(1, 1) = camera->getUp().getY();
    rotate(1, 2) = camera->getUp().getZ();

    rotate(2, 0) = camera->getForward().getX();
    rotate(2, 1) = camera->getForward().getY();
    rotate(2, 2) = camera->getForward().getZ();

    rotate(3, 3) = 1;

    transform_matrix = rotate;

    MoveAction toCenter(-camera->getCenter().getX(), -camera->getCenter().getY(), -camera->getCenter().getZ());

    transform_matrix *= toCenter.getMatrix();
}
