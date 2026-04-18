#ifndef BASE_EXCEPTION_HPP__

#define BASE_EXCEPTION_HPP__

#include "base_exception.h"

BaseException::BaseException(const char *filename, const char *classname, int line, const char *err_info) noexcept
{
    snprintf(err_msg, ERR_MSG_SIZE, "File: %s, Classname: %s, Line: %d, Error_message: %s", filename, classname, line, err_info);
}

const char *BaseException::what() const noexcept
{
    return err_msg;
}

#endif
