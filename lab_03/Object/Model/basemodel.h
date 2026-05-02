#ifndef BASEMODEL_H
#define BASEMODEL_H

#include "visibleobject.h"
#include "modelstructure.h"
#include "point.h"

#include <memory>

class BaseModel: public VisibleObject
{
public:
    BaseModel();
    virtual ~BaseModel() = 0;

    Point getCenter();

protected:
    std::shared_ptr<ModelStructure> structure;
};

#endif // BASEMODEL_H
