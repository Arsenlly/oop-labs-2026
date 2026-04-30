#ifndef BASE_LIST_H__

#define BASE_LIST_H__

#include <cstddef>

class BaseList
{
    public:
        virtual bool empty() const noexcept = 0;
        virtual void clear() noexcept = 0;
        virtual size_t size() const noexcept = 0;
        virtual ~BaseList() = default;    
    
    protected:
        size_t _size = 0;
};

#endif
