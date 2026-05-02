#include "scenefacade.h"

SceneFacade::SceneFacade()
{
    _sceneManager = std::make_shared<SceneManager>();
    _transformManager = std::make_shared<TransformManager>();
    _drawManager = std::make_shared<DrawManager>();
    _loadManager = std::make_shared<LoadManager>();
}

void SceneFacade::execute(BaseCommand &command)
{
    command.setManagers(_transformManager, _drawManager, _loadManager, _sceneManager);
    command.execute();
}
