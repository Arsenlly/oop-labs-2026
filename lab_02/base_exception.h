#ifndef BASE_EXCEPTION_H__

#define BASE_EXCEPTION_H__

#define ERR_MSG_SIZE 512

#include <exception>
#include <cstdio>

class BaseException: public std::exception
{
    public:
        BaseException(const char *filename, const char *classname, int line, const char *err_info) noexcept;

        const char *what() const noexcept override;

    protected:
        char err_msg[ERR_MSG_SIZE];
};

#include "base_exception.hpp"

#endif
