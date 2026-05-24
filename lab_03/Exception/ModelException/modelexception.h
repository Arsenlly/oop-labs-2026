#ifndef MODELEXCEPTION_H
#define MODELEXCEPTION_H

#include "baseexception.h"

class InvalidFileFormatError: public BaseException
{
public:
    InvalidFileFormatError(const char *err_info) noexcept;
};

class InvalidQuanPointInFileError: public BaseException
{
public:
    InvalidQuanPointInFileError(const char *err_info) noexcept;
};

class InvalidPointInFileError: public BaseException
{
public:
    InvalidPointInFileError(const char *err_info) noexcept;
};

class InvalidQuanEdgeInFileError: public BaseException
{
public:
    InvalidQuanEdgeInFileError(const char *err_info) noexcept;
};

class InvalidEdgeInFileError: public BaseException
{
public:
    InvalidEdgeInFileError(const char *err_info) noexcept;
};

class InvalidInternalReprId: public BaseException
{
public:
    InvalidInternalReprId(const char *err_info) noexcept;
};

#endif // MODELEXCEPTION_H
