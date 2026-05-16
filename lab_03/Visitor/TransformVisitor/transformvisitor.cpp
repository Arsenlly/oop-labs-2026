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
}

void TransformVisitor::visit(Camera &camera) const
{
    // TODO пока не ясно
}
