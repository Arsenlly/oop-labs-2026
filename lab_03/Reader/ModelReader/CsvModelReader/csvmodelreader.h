#ifndef CSVMODELREADER_H
#define CSVMODELREADER_H

#include "modelreader.h"

class CsvModelReader: public ModelReader
{
public:
    CsvModelReader() = delete;
    CsvModelReader(const std::string &filename);

    virtual std::shared_ptr<std::vector<Point>> readPoints() override;
    virtual std::shared_ptr<std::vector<Edge>> readEdges() override;
};

#endif // CSVMODELREADER_H
