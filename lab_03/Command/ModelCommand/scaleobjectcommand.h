#ifndef SCALEOBJECTCOMMAND_H
#define SCALEOBJECTCOMMAND_H

#include "baseobjectcommand.h"
#include "point.h"

#include <cstddef>

class ScaleModelCommand: public BaseModelCommand
{
public:
    ScaleModelCommand() = delete;
    virtual ~ScaleModelCommand() = default;
    ScaleModelCommand(std::size_t id, Point &center, double kx, double ky, double kz);

    virtual void execute() override;

private:
    std::size_t _id;
    Point _center;
    double _kx;
    double _ky;
    double _kz;
};

#endif // SCALEOBJECTCOMMAND_H
