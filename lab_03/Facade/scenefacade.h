#ifndef SCENEFACADE_H
#define SCENEFACADE_H

#include "basecommand.h"
#include "transformmanager.h"
#include "loadmanager.h"
#include "drawmanager.h"

#include <memory>

class SceneFacade
{
public:
    void execute(BaseCommand &command);

private:
    std::shared_ptr<DrawManager> _drawManager;
    std::shared_ptr<LoadManager> _loadManager;
    std::shared_ptr<TransformManager> _transformManager;
};

#endif // SCENEFACADE_H
