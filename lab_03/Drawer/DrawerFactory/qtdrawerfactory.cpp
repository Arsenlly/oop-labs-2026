#include "qtdrawerfactory.h"

QtDrawerFactory::QtDrawerFactory(QGraphicsScene* scene)
{
    _scene = scene;
}

std::shared_ptr<BaseDrawer> QtDrawerFactory::createDrawer()
{
    return std::make_shared<QtDrawer>(_scene);
}
