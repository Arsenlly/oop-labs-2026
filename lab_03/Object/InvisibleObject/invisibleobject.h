#ifndef INVISIBLEOBJECT_H
#define INVISIBLEOBJECT_H

#include "object.h"

class InVisibleObject: public Object
{
public:
    InVisibleObject() = default;
    virtual ~InVisibleObject() = 0;
};

#endif // INVISIBLEOBJECT_H
