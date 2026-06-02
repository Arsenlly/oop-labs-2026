#include "directorsolution.h"

DirectorSolution::DirectorSolution()
{
    registerCreator(SkeletonModelDirectorId, std::make_shared<ConcreteDirectorCreator<SkeletonModelDirector>>());
}

void DirectorSolution::registerCreator(ModelDirectorId dir_id, std::shared_ptr<BaseDirectorCreator> new_creator)
{
    _creators[dir_id] = new_creator;
}

std::shared_ptr<BaseDirector> DirectorSolution::create(ModelDirectorId dir_id, std::shared_ptr<ModelReader> reader, InternalReprId repr_id)
{
    auto it = _creators.find(dir_id);

    return it->second->create(reader, repr_id);
}
