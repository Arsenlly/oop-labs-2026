#ifndef MATRIXMODELSTRUCTURE_H
#define MATRIXMODELSTRUCTURE_H

#include "modelstructure.h"
#include "point.h"
#include "edge.h"

#include <vector>

class MatrixModelStructure: public ModelStructure
{
public:
    MatrixModelStructure();

    virtual void addPoint(const Point &point) override;
    virtual void addEdge(const Edge &edge) override;

    virtual std::vector<Point> getPoints() override;
    virtual std::vector<Edge> getEdges() override;

    virtual void setPoints(std::vector<Point> points) override;

    virtual void transform(TransformAction &action) override;

private:
    void resizeMatrix(size_t size);

private:
    std::vector<Point> _points;
    std::vector<std::vector<bool>> _link_matrix;
};

#endif // MATRIXMODELSTRUCTURE_H
