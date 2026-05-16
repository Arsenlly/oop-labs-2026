#include "csvmodelreader.h"

CsvModelReader::CsvModelReader(const std::string &filename): ModelReader(filename) {}

std::shared_ptr<std::vector<Point>> CsvModelReader::readPoints()
{
}

std::shared_ptr<std::vector<Edge>> CsvModelReader::readEdges()
{
}

