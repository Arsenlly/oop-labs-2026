#include "baseexception.h"

BaseException::BaseException(const char *err_info) noexcept
{
    snprintf(err_msg, ERR_MSG_SIZE, "%s\n", err_info);
}

const char *BaseException::what() const noexcept
{
    return err_msg;
}
