#ifndef CONCRETEBUILDERCREATOR_HPP
#define CONCRETEBUILDERCREATOR_HPP

#include "concretebuildercreator.h"

template <typename BuilderType>
std::shared_ptr<BaseModelBuilder> ConcreteBuilderCreator<BuilderType>::create(std::shared_ptr<ModelReader> reader)
{
    return std::make_shared<BuilderType>(reader);
}

#endif // CONCRETEBUILDERCREATOR_HPP
