#include "concretedirectorcreator.h"

template<typename DirectorType>
std::shared_ptr<BaseDirector> ConcreteDirectorCreator<DirectorType>::create(std::shared_ptr<ModelReader> reader, InternalReprId repr_id)
{
    return std::make_shared<DirectorType>(reader, repr_id);
}
