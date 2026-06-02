#ifndef VISIBLEOBJECT_H
#define VISIBLEOBJECT_H

#include "object.h"

class VisibleObject: public Object
{
public:
    VisibleObject() = default;
    virtual ~VisibleObject() = 0;

    virtual bool isVisible() const noexcept override;
    virtual bool isComposite() const noexcept override;
};

#endif // VISIBLEOBJECT_H
