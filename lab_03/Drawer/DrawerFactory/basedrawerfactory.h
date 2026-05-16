#ifndef BASEDRAWERFACTORY_H
#define BASEDRAWERFACTORY_H

#include "basedrawer.h"

#include <memory>

class BaseDrawerFactory
{
public:
    BaseDrawerFactory() = default;

    virtual ~BaseDrawerFactory() = 0;

    virtual std::shared_ptr<BaseDrawer> createDrawer() = 0;
};

#endif // BASEDRAWERFACTORY_H
