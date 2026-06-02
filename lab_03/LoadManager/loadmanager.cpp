#include "loadmanager.h"

#include "skeletonmodeldirector.h"
static_assert(sizeof(SkeletonModelDirector) > 0, "type is visible");

LoadManager::LoadManager()
{
    rsol = std::make_shared<ReaderSolution>();
    dsol = std::make_shared<DirectorSolution>();
}

void LoadManager::load(std::shared_ptr<SceneManager> scene_manager, InternalReprId repr_id, const std::string &filename)
{
    std::shared_ptr<ModelReader> reader = rsol->create(filename);

    std::shared_ptr<BaseDirector> mdir = dsol->create(SkeletonModelDirectorId, reader, repr_id);

    std::shared_ptr<Object> obj = mdir->create();

    scene_manager->addObject(obj);
}
