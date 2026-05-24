#include "point.h"

Point::Point(const double x, const double y, const double z)
{
    _x = x;
    _y = y;
    _z = z;
    _w = 1;
}

Point::Point(const double x, const double y, const double z, const double w)
{
    _x = x;
    _y = y;
    _z = z;
    _w = w;
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

double Point::getW() const
{
    return _w;
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

void Point::setW(const double w)
{
    _w = w;
}
