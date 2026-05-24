#include "transformvisitor.h"

#include <iostream>

TransformVisitor::TransformVisitor(TransformAction &action): _action(action) {}

void TransformVisitor::visit(std::shared_ptr<ModelStructure> model) const
{
    std::vector<Point> points = model->getPoints();

    for (auto &p: points)
    {
        _action.transformPoint(p);
    }

    model->setPoints(points);

    Point center = model->getCenter();

    _action.transformPoint(center);

    model->setCenter(center);
}

void TransformVisitor::visit(Camera &camera) const
{
    Point pos = camera.getCenter();
    Point right = camera.getRight();
    Point up = camera.getUp();
    Point forward = camera.getForward();

    _action.transformPoint(pos);
    _action.transformPoint(right);
    _action.transformPoint(up);
    _action.transformPoint(forward);

    camera.setCenter(pos);
    camera.setRight(right);
    camera.setUp(up);
    camera.setForward(forward);
}
