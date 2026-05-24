#include "edge.h"

Edge::Edge(const std::size_t start, const std::size_t end)
{
    _start = start;
    _end = end;
}

std::size_t Edge::getStart() const
{
    return _start;
}

std::size_t Edge::getEnd() const
{
    return _end;
}

void Edge::setStart(const std::size_t start)
{
    _start = start;
}

void Edge::setEnd(const std::size_t end)
{
    _end = end;
}
