#ifndef LOADMODELCOMMAND_H
#define LOADMODELCOMMAND_H

#include "basemodelcommand.h"
#include "ids.h"

#include <string>

class LoadModelCommand: public BaseModelCommand
{
public:
    LoadModelCommand() = delete;
    LoadModelCommand(const InternalReprId repr_id, const std::string &filename);

    virtual ~LoadModelCommand() = default;

    virtual void execute() override;

private:
    InternalReprId _repr;
    std::string _filename;

};

#endif // LOADMODELCOMMAND_H
