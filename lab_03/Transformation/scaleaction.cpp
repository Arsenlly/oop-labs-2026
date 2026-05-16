#include "scaleaction.h"

ScaleAction::ScaleAction(double kx, double ky, double kz)
{
    transform_matrix.setIdentity();
    transform_matrix(0, 0) = kx;
    transform_matrix(1, 1) = ky;
    transform_matrix(2, 2) = kz;
}
