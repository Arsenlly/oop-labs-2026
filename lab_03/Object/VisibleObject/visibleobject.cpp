#include "visibleobject.h"

VisibleObject::~VisibleObject() {}

bool VisibleObject::isVisible() const noexcept
{
    return true;
}

bool VisibleObject::isComposite() const noexcept
{
    return false;
}
