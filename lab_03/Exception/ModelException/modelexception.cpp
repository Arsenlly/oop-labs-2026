#include "modelexception.h"

InvalidFileFormatError::InvalidFileFormatError(const char *err_info) noexcept:
    BaseException(err_info) {}

InvalidQuanPointInFileError::InvalidQuanPointInFileError(const char *err_info) noexcept:
    BaseException(err_info) {}

InvalidPointInFileError::InvalidPointInFileError(const char *err_info) noexcept:
    BaseException(err_info) {}

InvalidQuanEdgeInFileError::InvalidQuanEdgeInFileError(const char *err_info) noexcept:
    BaseException(err_info) {}

InvalidEdgeInFileError::InvalidEdgeInFileError(const char *err_info) noexcept:
    BaseException(err_info) {}
