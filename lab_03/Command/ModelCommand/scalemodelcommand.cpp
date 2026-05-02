#include "scalemodelcommand.h"

ScaleModelCommand::ScaleModelCommand(std::size_t id, double kx, double ky, double kz)
{
    _id = id;
    _kx = kx;
    _ky = ky;
    _kz = kz;
}

void ScaleModelCommand::execute()
{

}
