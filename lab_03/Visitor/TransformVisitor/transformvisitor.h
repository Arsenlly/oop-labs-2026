#ifndef TRANSFORMVISITOR_H
#define TRANSFORMVISITOR_H

#include "visitor.h"
#include "object.h"
#include "transformaction.h"
#include "point.h"
#include "camera.h"

#include <memory>
#include <vector>

class TransformVisitor: public Visitor
{
public:
    TransformVisitor() = delete;
    TransformVisitor(TransformAction &action);

    virtual ~TransformVisitor() override = default;

    virtual void visit(std::shared_ptr<ModelStructure> model) const override;
    virtual void visit(Camera &camera) const override;

protected:
    TransformAction &_action;
};

#endif // TRANSFORMVISITOR_H
