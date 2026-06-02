#include "scaleobjectcommand.h"

ScaleModelCommand::ScaleModelCommand(std::size_t id, Point &center, double kx, double ky, double kz)
{
    _id = id;
    _center = center;
    _kx = kx;
    _ky = ky;
    _kz = kz;
}

void ScaleModelCommand::execute()
{
    _transformManager->ScaleObject(_sceneManager, _id, _center, _kx, _ky, _kz);
}
