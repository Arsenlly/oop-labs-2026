#ifndef LISTMODELBUILDER_H
#define LISTMODELBUILDER_H

#include "basemodelbuilder.h"
#include "modelstructure.h"
#include "listmodelstructure.h"

#include <memory>
#include <ranges>
#include <algorithm>

class ListModelBuilder: public BaseModelBuilder
{
public:
    ListModelBuilder() = delete;

    ListModelBuilder(std::shared_ptr<ModelReader> reader);

    virtual ~ListModelBuilder() override = default;

    virtual void reset() override;

    virtual void buildPoints() override;
    virtual void buildEdges() override;
    virtual void buildCenter() override;

    virtual std::shared_ptr<BaseModel> getResult() override;
};

#endif // LISTMODELBUILDER_H
