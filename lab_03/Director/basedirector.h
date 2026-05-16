#ifndef BASEDIRECTOR_H
#define BASEDIRECTOR_H

#include "object.h"
#include "basemodelbuilder.h"

#include <memory>

class BaseDirector
{
public:
    BaseDirector() = default;
    virtual ~BaseDirector() = 0;

    virtual std::shared_ptr<Object> create(std::shared_ptr<BaseModelBuilder> builder) = 0;
};

#endif // BASEDIRECTOR_H
