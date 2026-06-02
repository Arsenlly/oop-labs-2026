#ifndef SKELETONMODELDIRECTOR_H
#define SKELETONMODELDIRECTOR_H

#include "basedirector.h"
#include "ids.h"
#include "modelreader.h"
#include "buildersolution.h"

#include <memory>

class SkeletonModelDirector: public BaseDirector
{
public:
    SkeletonModelDirector() = delete;
    SkeletonModelDirector(std::shared_ptr<ModelReader> reader, InternalReprId repr_id);

    virtual ~SkeletonModelDirector() override = default;

    virtual std::shared_ptr<Object> create() override;

private:
    BuilderSolution bsol;
    std::shared_ptr<BaseModelBuilder> builder;
};

#endif // SKELETONMODELDIRECTOR_H
