#include "removeobjectcommand.h"

RemoveObjectCommand::RemoveObjectCommand(size_t id)
{
    _id = id;
}

void RemoveObjectCommand::execute()
{
    _sceneManager->removeObject(_id);
}
