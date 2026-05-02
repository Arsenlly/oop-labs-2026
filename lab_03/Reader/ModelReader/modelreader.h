#ifndef MODELREADER_H
#define MODELREADER_H

#include "basereader.h"
#include "point.h"
#include "edge.h"

#include <string>
#include <fstream>
#include <vector>
#include <memory>

class ModelReader: public BaseReader
{
public:
    ModelReader() = delete;
    ModelReader(const std::string &filename);

    virtual std::shared_ptr<std::vector<Point>> readPoints() = 0;
    virtual std::shared_ptr<std::vector<Edge>> readEdges() = 0;

protected:
    std::ifstream model_file;
};

#endif // MODELREADER_H
