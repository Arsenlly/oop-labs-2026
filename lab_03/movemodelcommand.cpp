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

}
