#include "invisibleobject.h"

InVisibleObject::~InVisibleObject() {}

bool InVisibleObject::isVisible() const noexcept
{
    return false;
}

bool InVisibleObject::isComposite() const noexcept
{
    return false;
}
