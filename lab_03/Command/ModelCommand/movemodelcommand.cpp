#include "movemodelcommand.h"

MoveModelCommand::MoveModelCommand(std::size_t id, double dx, double dy, double dz)
{
    _id = id;
    _dx = dx;
    _dy = dy;
    _dz = dz;
}

void MoveModelCommand::execute()
{
    std::shared_ptr<Object> object = _sceneManager->getObject(_id);
    _transformManager->MoveObject(object, _dx, _dy, _dz);
}
