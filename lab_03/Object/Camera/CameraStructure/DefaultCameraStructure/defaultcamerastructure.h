#ifndef DEFAULTCAMERASTRUCTURE_H
#define DEFAULTCAMERASTRUCTURE_H

#include "basecamerastructure.h"
#include "point.h"
#include "moveaction.h"

class DefaultCameraStructure: public BaseCameraStructure
{
public:
    DefaultCameraStructure();

    virtual ~DefaultCameraStructure() override = default;

    virtual Eigen::Matrix4d getViewMatrix() override;

    virtual void transform(TransformAction &action) override;

private:
    Point _pos;
    Point _forward;
    Point _up;
    Point _right;
};

#endif // DEFAULTCAMERASTRUCTURE_H
