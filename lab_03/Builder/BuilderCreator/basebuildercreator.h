#ifndef BASEBUILDERCREATOR_H
#define BASEBUILDERCREATOR_H

#include "basemodelbuilder.h"
#include "modelreader.h"

#include <memory>

class BaseBuilderCreator
{
public:
    BaseBuilderCreator() = default;
    virtual ~BaseBuilderCreator() = 0;

    virtual std::shared_ptr<BaseModelBuilder> create(std::shared_ptr<ModelReader>) = 0;
};

#endif // BASEBUILDERCREATOR_H
