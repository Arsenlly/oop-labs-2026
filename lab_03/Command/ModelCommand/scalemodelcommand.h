#ifndef SCALEMODELCOMMAND_H
#define SCALEMODELCOMMAND_H

#include "basemodelcommand.h"

#include <cstddef>

class ScaleModelCommand: public BaseModelCommand
{
public:
    ScaleModelCommand() = delete;
    virtual ~ScaleModelCommand() = default;
    ScaleModelCommand(std::size_t id, double kx, double ky, double kz);

    virtual void execute() override;

private:
    std::size_t _id;
    double _kx;
    double _ky;
    double _kz;
};

#endif // SCALEMODELCOMMAND_H
