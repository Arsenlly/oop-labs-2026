#ifndef CONCRETEREADERCREATOR_HPP

#define CONCRETEREADERCREATOR_HPP

#include "concretereadercreator.h"

template<typename ReaderType>
std::shared_ptr<ModelReader> ConcreteReaderCreator<ReaderType>::create()
{
    return std::make_shared<ReaderType>;
}

#endif
