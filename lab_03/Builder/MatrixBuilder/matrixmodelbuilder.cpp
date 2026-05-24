#include "matrixmodelbuilder.h"

#include <iostream>

MatrixModelBuilder::MatrixModelBuilder(std::shared_ptr<ModelReader> reader): BaseModelBuilder(reader) {}

void MatrixModelBuilder::reset()
{
    std::shared_ptr<ModelStructure> structure = std::make_shared<MatrixModelStructure>();
    _model = std::make_shared<SkeletonModel>(structure);
}

void MatrixModelBuilder::buildPoints()
{
    std::shared_ptr<std::vector<Point>> points = _reader->readPoints();
    std::ranges::for_each(*points, [this](const Point &p){this->_model->getStructure()->addPoint(p);});
}

void MatrixModelBuilder::buildEdges()
{
    std::shared_ptr<std::vector<Edge>> edges = _reader->readEdges();
    std::ranges::for_each(*edges, [this](const Edge &e){this->_model->getStructure()->addEdge(e);});
}

void MatrixModelBuilder::buildCenter()
{
    std::vector<Point> points = _model->getStructure()->getPoints();

    double x;
    double y;
    double z;

    for (auto &p : points)
    {
        x += p.getX();
        y += p.getY();
        z += p.getZ();
    }

    _model->getStructure()->setCenter(Point(x / points.size(), y / points.size(), z / points.size()));
}

std::shared_ptr<BaseModel> MatrixModelBuilder::getResult()
{
    return _model;
}
