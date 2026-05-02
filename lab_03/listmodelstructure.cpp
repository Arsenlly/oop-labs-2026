#include "listmodelstructure.h"

ListModelStructure::ListModelStructure() {}

void ListModelStructure::addPoint(const Point &point) override
{
    _points.push_back(point);
}

void ListModelStructure::addEdge(const Edge &edge)
{
    _edges.push_back(edge);
}
