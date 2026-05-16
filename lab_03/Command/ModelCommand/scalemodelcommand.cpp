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
    std::shared_ptr<Object> object = _sceneManager->getObject(_id);
    _transformManager->ScaleObject(object, _kx, _ky, _kz);
}
