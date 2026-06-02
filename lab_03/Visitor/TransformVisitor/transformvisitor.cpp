#include "transformvisitor.h"

#include <iostream>

TransformVisitor::TransformVisitor(TransformAction &action): _action(action) {}

void TransformVisitor::visit(std::shared_ptr<ModelStructure> model_structure) const
{
    model_structure->transform(_action);
}

void TransformVisitor::visit(std::shared_ptr<BaseCameraStructure> camera_structure) const
{
    camera_structure->transform(_action);
}
