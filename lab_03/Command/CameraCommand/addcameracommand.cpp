#include "addcameracommand.h"

AddCameraCommand::AddCameraCommand(const Point &pos)
{
    _pos = pos;
}

void AddCameraCommand::execute()
{
    std::shared_ptr<Camera> camera = std::make_shared<Camera>(_pos);

    _sceneManager->addObject(camera);
}
