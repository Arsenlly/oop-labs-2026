#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include "scene.h"
#include "camera.h"

#include <memory>

class SceneManager
{
public:
    SceneManager();
    ~SceneManager() = default;

    std::shared_ptr<Scene> getScene();
    std::shared_ptr<Camera> getCurCamera();

    void addObject(std::shared_ptr<Object> obj);
    std::shared_ptr<Object> getObject(size_t id);

private:
    std::shared_ptr<Scene> _scene;
    std::shared_ptr<Camera> _camera;
};

#endif // SCENEMANAGER_H
