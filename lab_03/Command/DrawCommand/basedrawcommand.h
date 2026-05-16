#ifndef BASEDRAWCOMMAND_H
#define BASEDRAWCOMMAND_H

#include "basecommand.h"

class BaseDrawCommand: public BaseCommand
{
public:
    BaseDrawCommand() = default;
    virtual ~BaseDrawCommand() = 0;
};

#endif // BASEDRAWCOMMAND_H
