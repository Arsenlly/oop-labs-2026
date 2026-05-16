#ifndef MOVEACTION_H
#define MOVEACTION_H

#include "transformaction.h"

class MoveAction: public TransformAction
{
public:
    MoveAction() = delete;
    MoveAction(double dx, double dy, double dz);

    virtual ~MoveAction() override = default;
};

#endif // MOVEACTION_H
