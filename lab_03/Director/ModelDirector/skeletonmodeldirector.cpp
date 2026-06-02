#include "skeletonmodeldirector.h"

SkeletonModelDirector::SkeletonModelDirector(std::shared_ptr<ModelReader> reader, InternalReprId repr_id)
{
    builder = bsol.create(repr_id, reader);
}

std::shared_ptr<Object> SkeletonModelDirector::create()
{
    builder->reset();
    builder->buildPoints();
    builder->buildEdges();
    builder->buildCenter();

    return std::make_shared<SkeletonModel>(builder->getResult());
}
