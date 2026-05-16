#include "drawqtcommand.h"

DRawQtCommand::DRawQtCommand(QGraphicsScene* scene)
{
    _scene = scene;
}

void DRawQtCommand::execute()
{
    auto scene = _sceneManager->getScene();
    auto camera = _sceneManager->getCurCamera();
    _drawManager->DrawScene<QtDrawerFactory, QGraphicsScene*>(scene, camera, _scene);
}
