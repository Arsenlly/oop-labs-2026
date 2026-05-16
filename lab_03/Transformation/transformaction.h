#ifndef TRANSFORMACTION_H
#define TRANSFORMACTION_H

#include <eigen3/Eigen/Dense>

class TransformAction
{
public:
    TransformAction() = default;
    virtual ~TransformAction() = 0;
    const Eigen::Matrix4d &getMatrix();

protected:
    Eigen::Matrix4d transform_matrix;
};

#endif // TRANSFORMACTION_H
