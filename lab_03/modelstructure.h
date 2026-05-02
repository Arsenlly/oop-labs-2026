#ifndef MODELSTRUCTURE_H
#define MODELSTRUCTURE_H

#include "point.h"
#include "edge.h"

class ModelStructure
{
public:
    ModelStructure();

    virtual void addPoint(const Point &point) = 0;
    virtual void addEdge(const Edge &edge) = 0;
};

#endif // MODELSTRUCTURE_H
