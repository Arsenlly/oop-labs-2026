#include "matrixmodelstructure.h"

MatrixModelStructure::MatrixModelStructure() {}

void MatrixModelStructure::addPoint(const Point &point)
{
    _points.push_back(point);
    resizeMatrix(_points.size());
}

void MatrixModelStructure::addEdge(const Edge &edge)
{
    size_t start = edge.getStart();
    size_t end = edge.getEnd();

    _link_matrix[end][start] = 1;
    _link_matrix[start][end] = 1;
}

std::vector<Point> MatrixModelStructure::getPoints()
{
    return _points;
}

std::vector<Edge> MatrixModelStructure::getEdges()
{
    std::vector<Edge> edges;

    for (size_t i = 0; i < _link_matrix.size(); ++i)
        for (size_t j = i + 1; j < _link_matrix.size(); ++j)
            if (_link_matrix[i][j])
                edges.emplace_back(i, j);

    return edges;
}

void MatrixModelStructure::setPoints(std::vector<Point> points)
{
    _points = points;
}

void MatrixModelStructure::resizeMatrix(size_t size)
{
    for (auto &row :_link_matrix)
        row.resize(size, 0);

    while(_link_matrix.size() < size)
        _link_matrix.emplace_back(size, 0);
}

void MatrixModelStructure::transform(TransformAction &action)
{
    for (auto &p: _points)
    {
        action.transformPoint(p);
    }

    action.transformPoint(_center);
}
