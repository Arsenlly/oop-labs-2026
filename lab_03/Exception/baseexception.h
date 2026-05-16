#ifndef BASEEXCEPTION_H
#define BASEEXCEPTION_H

#define ERR_MSG_SIZE 512

#include <exception>
#include <cstdio>

class BaseException: public std::exception
{
public:
    BaseException(const char *err_info) noexcept;
    virtual const char *what() const noexcept override;

protected:
    char err_msg[ERR_MSG_SIZE];
};

#endif // BASEEXCEPTION_H
