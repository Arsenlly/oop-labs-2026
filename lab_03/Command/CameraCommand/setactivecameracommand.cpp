#include "setactivecameracommand.h"

SetActiveCameraCommand::SetActiveCameraCommand(size_t id)
{
    _id = id;
}

void SetActiveCameraCommand::execute()
{
    _sceneManager->setCurCamera(_id);
}
