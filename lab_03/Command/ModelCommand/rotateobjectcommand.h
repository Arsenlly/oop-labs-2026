#ifndef ROTATEOBJECTCOMMAND_H
#define ROTATEOBJECTCOMMAND_H

#include "baseobjectcommand.h"
#include "point.h"

class RotateModelCommand: public BaseModelCommand
{
public:
    RotateModelCommand() = delete;
    virtual ~RotateModelCommand() = default;
    RotateModelCommand(std::size_t id, Point &center, double x_angle, double y_angle, double z_angle);

    virtual void execute() override;

private:
    std::size_t _id;
    Point _center;
    double _x_angle;
    double _y_angle;
    double _z_angle;
};

#endif // ROTATEOBJECTCOMMAND_H
