#ifndef SCALEACTION_H
#define SCALEACTION_H

#include "transformaction.h"
#include "moveaction.h"
#include "point.h"

class ScaleAction: public TransformAction
{
public:
    ScaleAction() = delete;
    ScaleAction(double kx, double ky, double kz);
    ScaleAction(const Point &center, double kx, double ky, double kz);

    virtual ~ScaleAction() override = default;
};

#endif // SCALEACTION_H
