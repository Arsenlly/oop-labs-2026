#ifndef ADDCAMERACOMMAND_H
#define ADDCAMERACOMMAND_H

#include "basecameracommand.h"
#include "camera.h"

#include <memory>

class AddCameraCommand: public BaseCameraCommand
{
public:
    AddCameraCommand() = delete;
    AddCameraCommand(const Point &pos);

    virtual ~AddCameraCommand() override = default;

    virtual void execute();

private:
    Point _pos;
};

#endif // ADDCAMERACOMMAND_H
