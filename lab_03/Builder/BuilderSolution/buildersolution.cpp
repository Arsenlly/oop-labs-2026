#include "buildersolution.h"

BuilderSolution::BuilderSolution()
{
    registerCreator(ListRepr, std::make_shared<ConcreteBuilderCreator<ListModelBuilder>>());
    registerCreator(MatrixRepr, std::make_shared<ConcreteBuilderCreator<MatrixModelBuilder>>());
}

void BuilderSolution::registerCreator(InternalReprId repr_id, std::shared_ptr<BaseBuilderCreator> new_creator)
{
    _creators[repr_id] = new_creator;
}

std::shared_ptr<BaseModelBuilder> BuilderSolution::create(InternalReprId repr_id, std::shared_ptr<ModelReader> reader)
{
    auto it = _creators.find(repr_id);

    if (it == _creators.end())
    {
        throw InvalidInternalReprId("Invalid internal representation id!");
    }
    return it->second->create(reader);
}
