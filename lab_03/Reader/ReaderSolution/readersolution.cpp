#include "readersolution.h"

ReaderSolution::ReaderSolution()
{
    registerCreator(".txt", std::make_shared<ConcreteReaderCreator<TxtModelReader>>());
    registerCreator(".csv", std::make_shared<ConcreteReaderCreator<CsvModelReader>>());
}

void ReaderSolution::registerCreator(const std::string ext, std::shared_ptr<BaseReaderCreator> newCreator)
{
    _creators[ext] = newCreator;
}

std::shared_ptr<ModelReader> ReaderSolution::create(const std::string &filename)
{
    std::string ext = std::filesystem::path(filename).extension().string();

    auto it = _creators.find(ext);

    if (it == _creators.end())
    {
        throw InvalidFileFormatError("File unsupported!");
    }
    return it->second->create(filename);
}
