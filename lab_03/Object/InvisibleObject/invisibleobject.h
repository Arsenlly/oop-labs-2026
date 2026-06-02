#ifndef INVISIBLEOBJECT_H
#define INVISIBLEOBJECT_H

#include "object.h"

class InVisibleObject: public Object
{
public:
    InVisibleObject() = default;
    virtual ~InVisibleObject() = 0;

    virtual bool isVisible() const noexcept override;
    virtual bool isComposite() const noexcept override;
};

#endif // INVISIBLEOBJECT_H
