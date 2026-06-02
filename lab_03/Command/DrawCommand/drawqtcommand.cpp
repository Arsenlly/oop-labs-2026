#include "drawqtcommand.h"

DRawQtCommand::DRawQtCommand(QGraphicsScene* scene)
{
    _scene = scene;
}

void DRawQtCommand::execute()
{
    _drawManager->DrawScene<QtDrawerFactory, QGraphicsScene*>(_sceneManager, _scene);
}
