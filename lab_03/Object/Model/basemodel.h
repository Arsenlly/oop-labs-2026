#ifndef BASEMODEL_H
#define BASEMODEL_H

#include "visibleobject.h"
#include "modelstructure.h"
#include "point.h"

#include <memory>

class BaseModel: public VisibleObject
{
public:
    BaseModel() = default;
    explicit BaseModel(std::shared_ptr<ModelStructure> structure);

    virtual ~BaseModel() = 0;

    Point getCenter();

    std::shared_ptr<ModelStructure> getStructure();

protected:
    std::shared_ptr<ModelStructure> _structure;
};

#endif // BASEMODEL_H
