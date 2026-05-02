#ifndef EDGE_H
#define EDGE_H

#include <cstddef>

class Edge
{
public:
    Edge() = default;
    Edge(const std::size_t start, const std::size_t end);

    std::size_t getStart();
    std::size_t getEnd();

    void setStart(const std::size_t start);
    void setEnd(const std::size_t end);

private:
    std::size_t _start;
    std::size_t _end;
};

#endif // EDGE_H
