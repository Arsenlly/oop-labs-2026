#ifndef ROTATEMODELCOMMAND_H
#define ROTATEMODELCOMMAND_H

#include "basemodelcommand.h"

class RotateModelCommand: public BaseModelCommand
{
public:
    RotateModelCommand() = delete;
    virtual ~RotateModelCommand() = default;
    RotateModelCommand(std::size_t id, double x_angle, double y_angle, double z_angle);

    virtual void execute() override;

private:
    std::size_t _id;
    double _x_angle;
    double _y_angle;
    double _z_angle;
};

#endif // ROTATEMODELCOMMAND_H
