#ifndef BASEDIRECTORCREATOR_H
#define BASEDIRECTORCREATOR_H

#include "ids.h"
#include "basedirector.h"

class BaseDirectorCreator
{
public:
    BaseDirectorCreator() = default;
    virtual ~BaseDirectorCreator() = 0;

    virtual std::shared_ptr<BaseDirector> create(std::shared_ptr<ModelReader> reader, InternalReprId repr_id) = 0;
};

#endif // BASEDIRECTORCREATOR_H
