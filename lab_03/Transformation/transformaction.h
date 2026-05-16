#ifndef TRANSFORMACTION_H
#define TRANSFORMACTION_H

#include "point.h"

#include <eigen3/Eigen/Dense>

class TransformAction
{
public:
    TransformAction() = default;
    virtual ~TransformAction() = 0;

    const Eigen::Matrix4d &getMatrix();

    void transformPoint(Point &p);

protected:
    Eigen::Matrix4d transform_matrix;
};

#endif // TRANSFORMACTION_H
