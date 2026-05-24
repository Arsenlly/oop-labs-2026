#ifndef DRAWVISITOR_H
#define DRAWVISITOR_H

#include "visitor.h"
#include "basedrawer.h"
#include "camera.h"
#include "projectioncameraaction.h"

#include <memory>

class DrawVisitor: public Visitor
{
public:
    DrawVisitor() = delete;

    DrawVisitor(std::shared_ptr<BaseDrawer> drawer, std::shared_ptr<Camera> camera);

    virtual ~DrawVisitor() override = default;

    virtual void visit(std::shared_ptr<ModelStructure> model) const override;
    virtual void visit(Camera &camera) const  override;

private:
    std::shared_ptr<BaseDrawer> _drawer;
    std::shared_ptr<Camera> _camera;
};

#endif // DRAWVISITOR_H
