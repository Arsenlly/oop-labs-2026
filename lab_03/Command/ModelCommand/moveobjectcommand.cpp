#include "moveobjectcommand.h"

MoveModelCommand::MoveModelCommand(std::size_t id, double dx, double dy, double dz)
{
    _id = id;
    _dx = dx;
    _dy = dy;
    _dz = dz;
}

void MoveModelCommand::execute()
{
    _transformManager->MoveObject(_sceneManager, _id, _dx, _dy, _dz);
}
