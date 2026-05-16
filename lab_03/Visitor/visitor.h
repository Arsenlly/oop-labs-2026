#ifndef VISITOR_H
#define VISITOR_H

#include "modelstructure.h"

#include <memory>

class Camera;
class ModelStructure;

class Visitor
{
public:
    Visitor() = default;
    virtual ~Visitor() = 0;

    virtual void visit(std::shared_ptr<ModelStructure> model) const = 0;
    virtual void visit(Camera &camera) const  = 0;
};

#endif // VISITOR_H
