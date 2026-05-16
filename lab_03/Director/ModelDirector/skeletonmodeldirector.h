#ifndef SKELETONMODELDIRECTOR_H
#define SKELETONMODELDIRECTOR_H

#include "basedirector.h"

class SkeletonModelDirector: public BaseDirector
{
public:
    SkeletonModelDirector() = default;
    virtual ~SkeletonModelDirector() override = default;

    virtual std::shared_ptr<Object> create(std::shared_ptr<BaseModelBuilder> builder) override;
};

#endif // SKELETONMODELDIRECTOR_H
