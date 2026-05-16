#ifndef MODELSTRUCTURE_H
#define MODELSTRUCTURE_H

#include "point.h"
#include "edge.h"

#include <vector>

class ModelStructure
{
public:
    ModelStructure();

    virtual void addPoint(const Point &point) = 0;
    virtual void addEdge(const Edge &edge) = 0;

    virtual const std::vector<Point>& getPoints() = 0;
    virtual const std::vector<Edge>& getEdges() = 0;

    const Point& getCenter();

protected:
    Point _center;
};

#endif // MODELSTRUCTURE_H
