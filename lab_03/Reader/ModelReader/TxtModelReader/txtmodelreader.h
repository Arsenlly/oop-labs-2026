#ifndef TXTMODELREADER_H
#define TXTMODELREADER_H

#include "modelreader.h"
#include "point.h"
#include "edge.h"
#include "modelexception.h"

#include <memory>
#include <vector>
#include <string>

class TxtModelReader: public ModelReader
{
public:
    TxtModelReader() = delete;
    TxtModelReader(const std::string &filename);

    virtual std::shared_ptr<std::vector<Point>> readPoints() override;
    virtual std::shared_ptr<std::vector<Edge>> readEdges() override;
};

#endif // TXTMODELREADER_H
