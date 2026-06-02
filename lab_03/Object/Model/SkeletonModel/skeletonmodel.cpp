#include "skeletonmodel.h"

SkeletonModel::SkeletonModel(std::shared_ptr<ModelStructure> structure): BaseModel(structure) {}

void SkeletonModel::accept(const Visitor &visitor)
{
    visitor.visit(_structure);
}
