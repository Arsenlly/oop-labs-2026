#ifndef ITERATOR_EXCEPTION_H__

#define ITERATOR_EXCEPTION_H__

#include "base_exception.h"

class IteratorExpiredError: public BaseException
{
    public:
        IteratorExpiredError(const char *filename, const char *classname, int line, const char *err_info) noexcept;
};

#include "iterator_exception.hpp"

#endif