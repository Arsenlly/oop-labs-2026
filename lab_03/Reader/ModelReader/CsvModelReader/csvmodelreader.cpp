#include "csvmodelreader.h"

CsvModelReader::CsvModelReader(const std::string &filename): ModelReader(filename) {}

std::shared_ptr<std::vector<Point>> CsvModelReader::readPoints()
{
    model_file.clear();
    model_file.seekg(0);
    size_t n_points;
    if (!(model_file >> n_points))
    {
        throw InvalidQuanPointInFileError("Incorrect quantity of points in the file");
    }

    if (n_points <= 0)
    {
        throw InvalidQuanPointInFileError("Incorrect quantity of points in the file");
    }

    std::vector<Point> points(n_points);
    double x, y, z;
    char separator;

    for(size_t i = 0;i < n_points;i++)
    {
        if (!(model_file >> x >> separator >> y >> separator >> z))
        {
            throw InvalidPointInFileError("Incorrect points in the file");
        }
        points[i] = Point(x, y, z);
    }
    return std::make_shared<std::vector<Point>>(std::move(points));
}

std::shared_ptr<std::vector<Edge>> CsvModelReader::readEdges()
{
    model_file.clear();
    size_t n_edges;
    if (!(model_file >> n_edges))
    {
        throw InvalidQuanEdgeInFileError("Incorrect quantity of edges in the file");
    }

    if (n_edges <= 0)
    {
        throw InvalidQuanEdgeInFileError("Incorrect quantity of edges in the file");
    }

    std::vector<Edge> edges(n_edges);
    size_t start, end;
    char separator;

    for(size_t i = 0;i < n_edges;i++)
    {
        if (!(model_file >> start >> separator >> end))
        {
            throw InvalidEdgeInFileError("Incorrect edges in the file");
        }
        edges[i] = Edge(start, end);
    }
    return std::make_shared<std::vector<Edge>>(std::move(edges));
}

