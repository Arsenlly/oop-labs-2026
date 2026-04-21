#ifndef BASE_CONTAINER_H__

#define BASE_CONTAINER_H__

#include <cstddef>

class BaseContainer
{
    public:
        virtual bool empty() const noexcept = 0;
        virtual void clear() noexcept = 0;
        virtual size_t size() const noexcept = 0;
        virtual ~BaseContainer() = default;    
    
    protected:
        size_t _size = 0;
};

#endif
