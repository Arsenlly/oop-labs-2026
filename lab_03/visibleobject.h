#ifndef VISIBLEOBJECT_H
#define VISIBLEOBJECT_H

#include "object.h"

class VisibleObject: public Object
{
public:
    VisibleObject() = default;
    virtual ~VisibleObject() = 0;
};

#endif // VISIBLEOBJECT_H
