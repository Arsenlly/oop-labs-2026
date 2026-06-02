#ifndef BASECAMERA_H
#define BASECAMERA_H

#include "basecamerastructure.h"
#include "invisibleobject.h"

#include <memory>

class BaseCamera: public InVisibleObject
{
    friend class CameraProjAdapter;

public:
    BaseCamera(std::shared_ptr<BaseCameraStructure> structure);

    virtual ~BaseCamera() = 0;

protected:
    std::shared_ptr<BaseCameraStructure> _structure;
};

#endif // BASECAMERA_H
