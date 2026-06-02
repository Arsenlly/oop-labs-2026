#ifndef BASEMODELBUILDER_H
#define BASEMODELBUILDER_H

#include "basemodel.h"
#include "modelreader.h"
#include "skeletonmodel.h"
#include "modelstructure.h"

#include <memory>

class BaseModelBuilder
{
public:
    BaseModelBuilder() = delete;
    BaseModelBuilder(std::shared_ptr<ModelReader> reader);

    virtual ~BaseModelBuilder() = 0;

    virtual void reset() = 0;

    virtual void buildPoints() = 0;
    virtual void buildEdges() = 0;
    virtual void buildCenter() = 0;

    virtual std::shared_ptr<ModelStructure> getResult() = 0;

protected:
    std::shared_ptr<ModelReader> _reader;
    std::shared_ptr<ModelStructure> _model;
};

#endif // BASEMODELBUILDER_H
