#include "loadmanager.h"

LoadManager::LoadManager()
{
    rsol = std::make_shared<ReaderSolution>();
    bsol = std::make_shared<BuilderSolution>();
}

std::shared_ptr<Object> LoadManager::load(InternalReprId repr_id, const std::string &filename)
{
    std::shared_ptr<ModelReader> reader = rsol->create(filename);

    std::shared_ptr<BaseModelBuilder> builder = bsol->create(repr_id, reader);

    SkeletonModelDirector mdir;

    return mdir.create(builder);
}
