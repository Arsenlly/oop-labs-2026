#ifndef CONCRETEBUILDERCREATOR_H
#define CONCRETEBUILDERCREATOR_H

#include "basebuildercreator.h"

#include <memory>

template<typename BuilderType>
class ConcreteBuilderCreator: public BaseBuilderCreator
{
public:
    ConcreteBuilderCreator() = default;
    virtual ~ConcreteBuilderCreator() override = default;

    virtual std::shared_ptr<BaseModelBuilder> create(std::shared_ptr<ModelReader>) override;
};

#include "concretebuildercreator.hpp"

#endif // CONCRETEBUILDERCREATOR_H
