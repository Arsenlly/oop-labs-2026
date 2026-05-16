#include "point.h"

Point::Point(const double x, const double y, const double z)
{
    _x = x;
    _y = y;
    _z = z;
}

double Point::getX() const
{
    return _x;
}

double Point::getY() const
{
    return _y;
}

double Point::getZ() const
{
    return _z;
}

void Point::setX(const double x)
{
    _x = x;
}

void Point::setY(const double y)
{
    _y = y;
}

void Point::setZ(const double z)
{
    _z = z;
}
