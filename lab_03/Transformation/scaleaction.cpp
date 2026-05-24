#include "scaleaction.h"

ScaleAction::ScaleAction(double kx, double ky, double kz)
{
    transform_matrix.setIdentity();
    transform_matrix(0, 0) = kx;
    transform_matrix(1, 1) = ky;
    transform_matrix(2, 2) = kz;
}

ScaleAction::ScaleAction(const Point &center, double kx, double ky, double kz)
{
    MoveAction moveFromCenter(center.getX(), center.getY(), center.getZ());

    transform_matrix = moveFromCenter.getMatrix();

    ScaleAction scale(kx, ky, kz);

    transform_matrix *= scale.getMatrix();

    MoveAction moveToCenter(-center.getX(), -center.getY(), -center.getZ());

    transform_matrix *= moveToCenter.getMatrix();
}

#include "rotateaction.h"
