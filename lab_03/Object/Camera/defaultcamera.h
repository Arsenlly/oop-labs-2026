#ifndef DEFAULTCAMERA_H
#define DEFAULTCAMERA_H

#include "basecamera.h"
#include "basecamerastructure.h"
#include "defaultcamerastructure.h"

#include <memory>

class DefaultCamera: public BaseCamera
{
public:
    DefaultCamera();

    virtual ~DefaultCamera() override = default;

    virtual void accept(const Visitor &visitor) override;
};

#endif // DEFAULTCAMERA_H
