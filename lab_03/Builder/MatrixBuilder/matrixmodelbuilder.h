#ifndef MATRIXMODELBUILDER_H
#define MATRIXMODELBUILDER_H

#include "basemodelbuilder.h"

class MatrixModelBuilder: public BaseModelBuilder
{
public:
    MatrixModelBuilder() = delete;

    MatrixModelBuilder(std::shared_ptr<ModelReader> reader);

    virtual ~MatrixModelBuilder() override = default;

    virtual void reset() override;

    virtual void buildPoints() override;
    virtual void buildEdges() override;
    virtual void buildCenter() override;

    virtual std::shared_ptr<BaseModel> getResult() override;
};

#endif // MATRIXMODELBUILDER_H
