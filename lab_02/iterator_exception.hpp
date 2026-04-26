#ifndef ITERATOR_EXCEPTION_HPP__

#define ITERATOR_EXCEPTION_HPP__

#include "iterator_exception.h"

IteratorExpiredError::IteratorExpiredError(const char *filename, const char *classname, int line, const char *err_info) noexcept:
BaseException(filename, classname, line, err_info){}

IteratorOutOfListError::IteratorOutOfListError(const char *filename, const char *classname, int line, const char *err_info) noexcept:
BaseException(filename, classname, line, err_info){}

#endif