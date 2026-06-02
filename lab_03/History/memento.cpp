#include "memento.h"

Memento::Memento(std::vector<Point> points)
{
    _points = points;
}

std::vector<Point> &Memento::getPoints()
{
    return _points;
}
