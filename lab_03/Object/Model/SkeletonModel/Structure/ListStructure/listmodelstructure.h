#ifndef LISTMODELSTRUCTURE_H
#define LISTMODELSTRUCTURE_H

#include "modelstructure.h"

#include <vector>

class ListModelStructure: public ModelStructure
{
public:
    ListModelStructure();

    virtual void addPoint(const Point &point) override;
    virtual void addEdge(const Edge &edge) override;

    virtual std::vector<Point> getPoints() override;
    virtual std::vector<Edge> getEdges() override;

    virtual void setPoints(std::vector<Point> points) override;


private:
    std::vector<Edge> _edges;
    std::vector<Point> _points;
};

#endif // LISTMODELSTRUCTURE_H
