#include "listmodelbuilder.h"

#include <iostream>

ListModelBuilder::ListModelBuilder(std::shared_ptr<ModelReader> reader): BaseModelBuilder(reader) {}

void ListModelBuilder::reset()
{
    std::shared_ptr<ModelStructure> structure = std::make_shared<ListModelStructure>();
    _model = std::make_shared<SkeletonModel>(structure);
}

void ListModelBuilder::buildPoints()
{
    std::shared_ptr<std::vector<Point>> points = _reader->readPoints();
    std::ranges::for_each(*points, [this](const Point &p){this->_model->getStructure()->addPoint(p);});
}

void ListModelBuilder::buildEdges()
{
    std::shared_ptr<std::vector<Edge>> edges = _reader->readEdges();
    std::ranges::for_each(*edges, [this](const Edge &e){this->_model->getStructure()->addEdge(e);});
}

void ListModelBuilder::buildCenter()
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

std::shared_ptr<BaseModel> ListModelBuilder::getResult()
{
    return _model;
}
