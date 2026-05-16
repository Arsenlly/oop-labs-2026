#include "qtdrawer.h"

QtDrawer::QtDrawer(QGraphicsScene* scene)
{
    _scene = scene;
}

void QtDrawer::drawLine(const Point &start, const Point &end)
{
    _scene->addLine(start.getX(), start.getY(), end.getX(), end.getY());
}

void QtDrawer::clear()
{
    _scene->clear();
}
