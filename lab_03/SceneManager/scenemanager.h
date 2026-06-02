#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include "scene.h"
#include "basecamera.h"
#include "sceneexception.h"
#include "caretaker.h"

#include <memory>

class SceneManager
{
public:
    SceneManager();
    ~SceneManager() = default;

    std::shared_ptr<Scene> getScene();
    std::shared_ptr<BaseCamera> getCurCamera();

    void setCurCamera(size_t id);

    void addObject(std::shared_ptr<Object> obj);
    std::shared_ptr<Object> getObject(size_t id);

    void removeObject(size_t id);

private:
    std::shared_ptr<Scene> _scene;
    std::shared_ptr<BaseCamera> _camera;
};

#endif // SCENEMANAGER_H
