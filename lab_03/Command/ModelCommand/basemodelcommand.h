#ifndef BASEMODELCOMMAND_H
#define BASEMODELCOMMAND_H

#include "basecommand.h"

class BaseModelCommand: public BaseCommand
{
public:
    BaseModelCommand() = default;
    virtual ~BaseModelCommand() = 0;
};

#endif // BASEMODELCOMMAND_H
