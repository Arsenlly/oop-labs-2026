#include "moveaction.h"

MoveAction::MoveAction(double dx, double dy, double dz)
{
    transform_matrix.setIdentity();
    transform_matrix(0, 3) = dx;
    transform_matrix(1, 3) = dy;
    transform_matrix(2, 3) = dz;
}
