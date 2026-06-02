#ifndef MEMENTO_H
#define MEMENTO_H

#include "point.h"

#include <vector>

class Memento
{
public:
    Memento() = delete;
    Memento(std::vector<Point> points);

    ~Memento() = default;

    std::vector<Point> &getPoints();

private:
    std::vector<Point> _points;
};

#endif // MEMENTO_H
