#ifndef ROTATEACTION_H
#define ROTATEACTION_H

#include "transformaction.h"

#include <cmath>

class RotateAction: public TransformAction
{
public:
    RotateAction() = delete;
    RotateAction(double x_angle, double y_angle, double z_angle);

    virtual ~RotateAction() override = default;
};

#endif // ROTATEACTION_H
