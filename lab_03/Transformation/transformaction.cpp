#include "transformaction.h"

TransformAction::~TransformAction() {}

const Eigen::Matrix4d &TransformAction::getMatrix()
{
    return transform_matrix;
}

void TransformAction::transformPoint(Point &p)
{
    Eigen::Vector4d vec(p.getX(), p.getY(), p.getZ(), p.getW());

    Eigen::Vector4d res = transform_matrix * vec;

    p.setX(res(0));
    p.setY(res(1));
    p.setZ(res(2));
    p.setW(res(3));
}
