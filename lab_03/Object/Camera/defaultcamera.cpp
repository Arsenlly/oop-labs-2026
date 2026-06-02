#include "defaultcamera.h"

DefaultCamera::DefaultCamera(): BaseCamera(std::make_shared<DefaultCameraStructure>()) {}

void DefaultCamera::accept(const Visitor &visitor)
{
    visitor.visit(_structure);
}
