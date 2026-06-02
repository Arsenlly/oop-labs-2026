#include "defaultcamerastructure.h"


DefaultCameraStructure::DefaultCameraStructure()
{
    _pos = Point(0, 0, -10);
    _forward = Point(0, 0, 1, 0);
    _up = Point(0, 1, 0, 0);
    _right = Point(1, 0, 0, 0);
}

Eigen::Matrix4d DefaultCameraStructure::getViewMatrix()
{
    Eigen::Matrix4d view;

    view.setZero();

    view(0, 0) = _right.getX();
    view(0, 1) = _right.getY();
    view(0, 2) = _right.getZ();

    view(1, 0) = _up.getX();
    view(1, 1) = _up.getY();
    view(1, 2) = _up.getZ();

    view(2, 0) = _forward.getX();
    view(2, 1) = _forward.getY();
    view(2, 2) = _forward.getZ();

    view(3, 3) = 1;

    MoveAction toCenter(-_pos.getX(), -_pos.getY(), -_pos.getZ());

    view *= toCenter.getMatrix();

    return view;
}

void DefaultCameraStructure::transform(TransformAction &action)
{
    action.transformPoint(_pos);
    action.transformPoint(_right);
    action.transformPoint(_up);
    action.transformPoint(_forward);
}
