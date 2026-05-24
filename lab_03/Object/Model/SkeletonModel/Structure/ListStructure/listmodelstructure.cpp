#include "listmodelstructure.h"

#include <iostream>

ListModelStructure::ListModelStructure() {}

void ListModelStructure::addPoint(const Point &point)
{
    _points.push_back(point);
}

void ListModelStructure::addEdge(const Edge &edge)
{
    _edges.push_back(edge);
}

std::vector<Point> ListModelStructure::getPoints()
{
    return _points;
}

std::vector<Edge> ListModelStructure::getEdges()
{
    return _edges;
}

void ListModelStructure::setPoints(std::vector<Point> points)
{
    _points = points;
}
