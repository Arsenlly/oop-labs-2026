#ifndef CONCRETEREADERCREATOR_H
#define CONCRETEREADERCREATOR_H

#include "basereadercreator.h"
#include "modelreader.h"

template<typename ReaderType>
class ConcreteReaderCreator: public BaseReaderCreator
{
public:
    ConcreteReaderCreator() = default;
    virtual ~ConcreteReaderCreator() override = default;

    virtual std::shared_ptr<ModelReader> create(const std::string &filename) override;
};

#include "concretereadercreator.hpp"

#endif // CONCRETEREADERCREATOR_H
