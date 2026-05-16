#include "skeletonmodeldirector.h"

std::shared_ptr<Object> SkeletonModelDirector::create(std::shared_ptr<BaseModelBuilder> builder)
{
    builder->reset();
    builder->buildPoints();
    builder->buildEdges();
    builder->buildCenter();
    return builder->getResult();
}
