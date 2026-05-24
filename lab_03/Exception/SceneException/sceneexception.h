#ifndef SCENEEXCEPTION_H
#define SCENEEXCEPTION_H

#include "baseexception.h"

class TryDeleteActiveCameraError: public BaseException
{
public:
    TryDeleteActiveCameraError(const char *err_info) noexcept;
};

#endif // SCENEEXCEPTION_H
