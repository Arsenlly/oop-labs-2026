#ifndef LISTMODELBUILDER_H
#define LISTMODELBUILDER_H

#include "basemodelbuilder.h"

class ListModelBuilder: public BaseModelBuilder
{
public:
    ListModelBuilder() = delete;

    ListModelBuilder(std::shared_ptr<ModelReader> reader);

    virtual ~ListModelBuilder() override = default;

    virtual void buildPOint() override;
    virtual void buildEdge() override;
    virtual void buildCenter() override;
};

#endif // LISTMODELBUILDER_H
