#include "sceneexception.h"

TryDeleteActiveCameraError::TryDeleteActiveCameraError(const char *err_info) noexcept:
    BaseException(err_info) {}
