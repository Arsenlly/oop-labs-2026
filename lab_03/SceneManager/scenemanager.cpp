#include "scenemanager.h"

SceneManager::SceneManager()
{
    _scene = std::make_shared<Scene>();
}

std::shared_ptr<Scene> SceneManager::getScene()
{
    return _scene;
}

std::shared_ptr<BaseCamera> SceneManager::getCurCamera()
{
    return _camera;
}

void SceneManager::setCurCamera(size_t id)
{
    _camera = std::dynamic_pointer_cast<BaseCamera>(_scene->getObject(id));
}

void SceneManager::addObject(std::shared_ptr<Object> obj)
{
    _scene->addObject(obj);
}

std::shared_ptr<Object> SceneManager::getObject(size_t id)
{
    return _scene->getObject(id);
}

void SceneManager::removeObject(size_t id)
{
    if (_camera == _scene->getObject(id))
        throw TryDeleteActiveCameraError("The active camera cannot be deleted!");
    return _scene->removeObject(id);
}
