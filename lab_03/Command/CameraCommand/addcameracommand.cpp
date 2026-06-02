#include "addcameracommand.h"

AddCameraCommand::AddCameraCommand(const Point &pos)
{
    _pos = pos;
}

void AddCameraCommand::execute()
{
    _sceneManager->addObject(std::make_shared<DefaultCamera>());
}
