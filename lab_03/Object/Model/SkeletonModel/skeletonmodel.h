#ifndef SKELETONMODEL_H
#define SKELETONMODEL_H

#include "basemodel.h"

class SkeletonModel final: public BaseModel
{
public:
    SkeletonModel() = default;
    explicit SkeletonModel(std::shared_ptr<ModelStructure> structure);

    virtual void accept(const Visitor &visitor) override;

};

#endif // SKELETONMODEL_H
