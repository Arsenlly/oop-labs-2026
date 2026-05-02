#include "txtmodelreader.h"

TxtModelReader::TxtModelReader(const std::string &filename): ModelReader(filename) {}

std::shared_ptr<std::vector<Point>> TxtModelReader::readPoints()
{
    model_file.clear();
    model_file.seekg(0);
    size_t n_points;
    if (!(model_file >> n_points))
    {
        // TODO кинуть исключение
    }

    if (n_points <= 0)
    {
        // TODO кинуть исключение
    }

    std::vector<Point> points(n_points);
    double x, y, z;

    for(size_t i = 0;i < n_points;i++)
    {
        if (!(model_file >> x >> y >> z))
        {
            // TODO кинуть исключение
        }
        points[i] = Point(x, y, z);
    }
    return std::make_shared<std::vector<Point>>(std::move(points));
}

std::shared_ptr<std::vector<Edge>> TxtModelReader::readEdges()
{
    model_file.clear();
    size_t n_edges;
    if (!(model_file >> n_edges))
    {
        // TODO кинуть исключение
    }

    if (n_edges <= 0)
    {
        // TODO кинуть исключение
    }

    std::vector<Edge> edges(n_edges);
    size_t start, end;

    for(size_t i = 0;i < n_edges;i++)
    {
        if (!(model_file >> start >> end))
        {
            // TODO кинуть исключение
        }
        edges[i] = Edge(start, end);
    }
    return std::make_shared<std::vector<Edge>>(std::move(edges));
}
