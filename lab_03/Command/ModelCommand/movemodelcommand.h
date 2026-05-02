#ifndef MOVEMODELCOMMAND_H
#define MOVEMODELCOMMAND_H

#include <cstddef>

#include "basemodelcommand.h"

class MoveModelCommand: public BaseModelCommand
{
public:
    MoveModelCommand() = delete;
    virtual ~MoveModelCommand() = default;
    MoveModelCommand(std::size_t id, double dx, double dy, double dz);

    virtual void execute() override;

private:
    std::size_t _id;
    double _dx;
    double _dy;
    double _dz;
};

#endif // MOVEMODELCOMMAND_H
