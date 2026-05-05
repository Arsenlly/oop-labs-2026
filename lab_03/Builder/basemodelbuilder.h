#ifndef BASEMODELBUILDER_H
#define BASEMODELBUILDER_H

#include "modelreader.h"
#include "basemodel.h".h"

#include <memory>

class BaseModelBuilder
{
public:
    BaseModelBuilder() = delete;
    BaseModelBuilder(std::shared_ptr<ModelReader> reader);

    virtual ~BaseModelBuilder() = 0;

    virtual void buildPOint() = 0;
    virtual void buildEdge() = 0;
    virtual void buildCenter() = 0;

protected:
    std::shared_ptr<ModelReader> _reader;
    std::shared_ptr<BaseModel> _object;
};

#endif // BASEMODELBUILDER_H
