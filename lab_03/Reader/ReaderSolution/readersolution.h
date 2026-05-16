#ifndef READERSOLUTION_H
#define READERSOLUTION_H

#include "modelreader.h"
#include "basereadercreator.h"
#include "concretereadercreator.h"
#include "txtmodelreader.h"
#include "csvmodelreader.h"
#include "modelexception.h"

#include <memory>
#include <string>
#include <map>
#include <filesystem>

class ReaderSolution
{
public:
    ReaderSolution();
    ~ReaderSolution() = default;

    void registerCreator(const std::string ext, std::shared_ptr<BaseReaderCreator> newCreator);

    std::shared_ptr<ModelReader> create(const std::string &filename);

private:
    std::map<std::string, std::shared_ptr<BaseReaderCreator>> _creators;
};

#endif // READERSOLUTION_H
