#ifndef CONCRETEREADERCREATOR_HPP

#define CONCRETEREADERCREATOR_HPP

#include "concretereadercreator.h"

template<typename ReaderType>
std::shared_ptr<ModelReader> ConcreteReaderCreator<ReaderType>::create(const std::string &filename)
{
    return std::make_shared<ReaderType>(filename);
}

#endif
