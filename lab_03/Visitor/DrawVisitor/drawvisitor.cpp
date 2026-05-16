#include "drawvisitor.h"

#include <iostream>

DrawVisitor::DrawVisitor(std::shared_ptr<BaseDrawer> drawer, std::shared_ptr<Camera> camera)
{
    _drawer = drawer;
    _camera = camera;
}

void DrawVisitor::visit(std::shared_ptr<ModelStructure> model) const
{
    std::cout << "visit\n";
    auto points = model->getPoints();
    auto edges = model->getEdges();

    // for (auto &edge : edges)
    // {
    //     Point &start = points[edge.getStart()];
    //     Point &end = points[edge.getEnd()];

    //     Point proj_start(start.getX() - _camera->getPos.getX(),
    //                      start.getY() - _camera->getPos.getY(),
    //                      start.getZ() - _camera->getPos.getZ());

    //     Point proj_end(end.getX() - _camera->getPos.getX(),
    //                    end.getY() - _camera->getPos.getY(),
    //                    end.getZ() - _camera->getPos.getZ());


    // }

    // TODO нормально сделать отрисовку
    for (auto &edge : edges)
    {
        Point &start = points[edge.getStart()];
        Point &end = points[edge.getEnd()];

        _drawer->drawLine(start, end);
    }
}

void DrawVisitor::visit(Camera &camera) const
{
    (void) camera;
}
