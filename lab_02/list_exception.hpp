#ifndef LIST_EXCEPTION_HPP__

#define LIST_EXCEPTION_HPP__

#include "list_exception.h"

ListAllocateError::ListAllocateError(const char *filename, const char *classname, int line, const char *err_info) noexcept:
BaseException(filename, classname, line, err_info){}

ListIsEmptyError::ListIsEmptyError(const char *filename, const char *classname, int line, const char *err_info) noexcept:
BaseException(filename, classname, line, err_info){}

#endif