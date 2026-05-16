#include "modelstructure.h"

ModelStructure::ModelStructure() {}

const Point& ModelStructure::getCenter()
{
    return _center;
}

void ModelStructure::setCenter(const Point &center)
{
    _center = center;
}
