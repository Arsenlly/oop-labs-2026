#ifndef SCALEACTION_H
#define SCALEACTION_H

#include "transformaction.h"

class ScaleAction: public TransformAction
{
public:
    ScaleAction() = delete;
    ScaleAction(double kx, double ky, double kz);

    virtual ~ScaleAction() override = default;
};

#endif // SCALEACTION_H
