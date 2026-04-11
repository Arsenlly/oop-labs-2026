#ifndef BASE_CONTAINER_H__

#define BASE_CONTAINER_H__

#include <cstddef>

class BaseСontainer
{
    public:
        virtual bool is_empty() = 0;
        virtual void clear() = 0;
        virtual size_t get_size() = 0;
        virtual ~BaseСontainer() = default;    
    
    protected:
        size_t size = 0;
};

#endif
