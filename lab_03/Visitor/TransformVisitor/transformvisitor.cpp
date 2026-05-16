#include "transformvisitor.h"

TransformVisitor::TransformVisitor(TransformAction &action): _action(action) {}

void TransformVisitor::visit(std::shared_ptr<ModelStructure> model) const
{

}

void TransformVisitor::visit(Camera &camera) const
{
    // TODO пока не ясно
}
