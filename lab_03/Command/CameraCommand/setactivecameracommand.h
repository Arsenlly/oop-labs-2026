#ifndef SETACTIVECAMERACOMMAND_H
#define SETACTIVECAMERACOMMAND_H

#include "basecameracommand.h"

class SetActiveCameraCommand: public BaseCameraCommand
{
public:
    SetActiveCameraCommand() = delete;
    SetActiveCameraCommand(size_t id);

    virtual ~SetActiveCameraCommand() override = default;

    virtual void execute() override;

private:
    size_t _id;
};

#endif // SETACTIVECAMERACOMMAND_H
