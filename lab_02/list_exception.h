#ifndef LIST_EXCEPTION_H__

#define LIST_EXCEPTION_H__

#include "base_exception.h"

class ListAllocateError: public BaseException
{
    public:
        ListAllocateError(const char *filename, const char *classname, int line, const char *err_info);
};

class ListIsEmptyError: public BaseException
{
    public:
        ListIsEmptyError(const char *filename, const char *classname, int line, const char *err_info);
};

#include "list_exception.hpp"

#endif