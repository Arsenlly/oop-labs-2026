#ifndef TXTMODELREADER_H
#define TXTMODELREADER_H

#include "modelreader.h"

#include <memory>
#include <vector>
#include <string>

class TxtModelReader: public ModelReader
{
public:
    TxtModelReader() = delete;
    TxtModelReader(const std::string &filename);

    virtual std::shared_ptr<std::vector<Point>> readPoints();
    virtual std::shared_ptr<std::vector<Edge>> readEdges();
};

#endif // TXTMODELREADER_H
