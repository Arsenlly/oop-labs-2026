#ifndef BASECAMERASTRUCTURE_H
#define BASECAMERASTRUCTURE_H

#include "transformaction.h"

#include <eigen3/Eigen/Dense>

class BaseCameraStructure
{


public:
    BaseCameraStructure() = default;

    virtual ~BaseCameraStructure() = 0;

    virtual Eigen::Matrix4d getViewMatrix() = 0;

    virtual void transform(TransformAction &action) = 0;
};

#endif // BASECAMERASTRUCTURE_H
