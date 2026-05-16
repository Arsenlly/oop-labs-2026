#ifndef OBJECT_H
#define OBJECT_H

#include "visitor.h"

class Object
{
    public:
        Object() = default;
        virtual ~Object() = 0;

        virtual void accept(const Visitor &visitor) = 0;
};

#endif // OBJECT_H
