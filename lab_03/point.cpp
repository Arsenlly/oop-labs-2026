#include "point.h"

Point::Point(const double x, const double y, const double z)
{
    _x = x;
    _y = y;
    _z = z;
}

double MainWindow::getX()
{
    return _x;
}

double MainWindow::getY()
{
    return _y;
}

double MainWindow::getZ()
{
    return _z;
}

void MainWindow::setX(const double x)
{
    _x = x;
}

void MainWindow::setY(const double y)
{
    _y = y;
}

void MainWindow::setZ(const double z)
{
    _z = z;
}
