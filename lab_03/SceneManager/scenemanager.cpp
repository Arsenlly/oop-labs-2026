#include "scenemanager.h"

SceneManager::SceneManager()
{
    _scene = std::make_shared<Scene>();
}

std::shared_ptr<Scene> SceneManager::getScene()
{
    return _scene;
}

std::shared_ptr<Camera> SceneManager::getCurCamera()
{
    return _camera;
}

void SceneManager::addObject(std::shared_ptr<Object> obj)
{
    _scene->addObject(obj);
}
