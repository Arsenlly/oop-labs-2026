#include "transformaction.h"

TransformAction::~TransformAction() {}

const Eigen::Matrix4d &TransformAction::getMatrix()
{
    return transform_matrix;
}
