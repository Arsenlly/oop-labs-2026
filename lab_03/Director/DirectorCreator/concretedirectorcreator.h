#ifndef CONCRETEDIRECTORCREATOR_H
#define CONCRETEDIRECTORCREATOR_H

#include "basedirectorcreator.h"

template<typename DirectorType>
class ConcreteDirectorCreator: public BaseDirectorCreator
{
public:
    ConcreteDirectorCreator() = default;
    virtual ~ConcreteDirectorCreator() override = default;

    virtual std::shared_ptr<BaseDirector> create(std::shared_ptr<ModelReader> reader, InternalReprId repr_id) override;
};

#include "concretedirectorcreator.hpp"

#endif // CONCRETEDIRECTORCREATOR_H
