#ifndef BASECOMMAND_H
#define BASECOMMAND_H

#include "transformmanager.h"
#include "drawmanager.h"
#include "loadmanager.h"
#include "scenemanager.h"

#include <memory>

class BaseCommand
{
public:
    using tm_ptr = std::shared_ptr<TransformManager>;
    using lm_ptr = std::shared_ptr<LoadManager>;
    using dm_ptr = std::shared_ptr<DrawManager>;
    using sm_ptr = std::shared_ptr<SceneManager>;

public:
    BaseCommand() = default;
    virtual ~BaseCommand() = default;

    virtual void execute() = 0;
    void setManagers(tm_ptr transformManager, dm_ptr drawManager, lm_ptr loadManager, sm_ptr sceneManager);

protected:
    tm_ptr _transformManager;
    dm_ptr _drawManager;
    lm_ptr _loadManager;
    sm_ptr _sceneManager;
};

#endif // BASECOMMAND_H
