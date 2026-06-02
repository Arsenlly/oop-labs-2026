#include "drawvisitor.h"

#include <iostream>

#define FOCUS 500.0
#define R (1 / FOCUS)

DrawVisitor::DrawVisitor(std::shared_ptr<BaseDrawer> drawer, std::shared_ptr<BaseCamera> camera)
{
    _drawer = drawer;
    _camera = camera;
}

void DrawVisitor::visit(std::shared_ptr<ModelStructure> model_structure) const
{
    auto points = model_structure->getPoints();
    auto edges = model_structure->getEdges();

    ProjectionCameraAction proj_action(_camera);

    for (auto &edge : edges)
    {
        Point start = points[edge.getStart()];
        Point end = points[edge.getEnd()];

        proj_action.transformPoint(start);
        proj_action.transformPoint(end);

        start.setX(start.getX() * (1 / (R * start.getZ())));
        start.setY(start.getY() * (1 / (R * start.getZ())));

        end.setX(end.getX() * (1 / (R * end.getZ())));
        end.setY(end.getY() * (1 / (R * end.getZ())));

        if (start.getZ() > 0 && end.getZ() > 0)
            _drawer->drawLine(start, end);
    }
}

void DrawVisitor::visit(std::shared_ptr<BaseCameraStructure> camera_structure) const
{
    (void) camera_structure;
}
