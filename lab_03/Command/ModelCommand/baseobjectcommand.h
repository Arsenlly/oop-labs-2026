#ifndef BASEOBJECTCOMMAND_H
#define BASEOBJECTCOMMAND_H

#include "basecommand.h"

class BaseModelCommand: public BaseCommand
{
public:
    BaseModelCommand() = default;
    virtual ~BaseModelCommand() = 0;
};

#endif // BASEOBJECTCOMMAND_H
