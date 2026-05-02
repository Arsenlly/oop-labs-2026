#ifndef BASEREADERCREATOR_H
#define BASEREADERCREATOR_H

#include "modelreader.h"

#include <memory>

class BaseReaderCreator
{
public:
    BaseReaderCreator() = default;
    virtual ~BaseReaderCreator() = default;

    virtual std::shared_ptr<ModelReader> create() = 0;
};

#endif // BASEREADERCREATOR_H
