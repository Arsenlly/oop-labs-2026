#include "readersolution.h"

void ReaderSolution::registerCreator(const std::string, std::shared_ptr<BaseReaderCreator> newCreator)
{

}

std::shared_ptr<ModelReader> ReaderSolution::create(const std::string &filename)
{

}
