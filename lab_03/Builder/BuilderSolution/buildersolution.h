#ifndef BUILDERSOLUTION_H
#define BUILDERSOLUTION_H

#include "basemodelbuilder.h"
#include "ids.h"
#include "modelreader.h"
#include "basebuildercreator.h"
#include "concretebuildercreator.h"
#include "listmodelbuilder.h"
#include "matrixmodelbuilder.h"

#include <memory>
#include <map>

class BuilderSolution
{
public:
    BuilderSolution();

    ~BuilderSolution() = default;

    void registerCreator(InternalReprId repr_id, std::shared_ptr<BaseBuilderCreator> new_creator);

    std::shared_ptr<BaseModelBuilder> create(InternalReprId repr_id, std::shared_ptr<ModelReader> reader);

private:
    std::map<InternalReprId, std::shared_ptr<BaseBuilderCreator>> _creators;
};

#endif // BUILDERSOLUTION_H
