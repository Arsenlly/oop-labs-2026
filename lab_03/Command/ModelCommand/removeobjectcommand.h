#ifndef REMOVEOBJECTCOMMAND_H
#define REMOVEOBJECTCOMMAND_H

#include "baseobjectcommand.h"

class RemoveObjectCommand: public BaseModelCommand
{
public:
    RemoveObjectCommand() = delete;
    RemoveObjectCommand(size_t id);

    virtual ~RemoveObjectCommand() override = default;

    virtual void execute() override;

private:
    size_t _id;
};

#endif // REMOVEOBJECTCOMMAND_H
