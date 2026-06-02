#include "object.h"

Object::~Object() {}

Object::iterator Object::begin()
{
    return iterator();
}

Object::iterator Object::end()
{
    return iterator();
}

Object::const_iterator Object::begin() const
{
    return const_iterator();
}

Object::const_iterator Object::end() const
{
    return const_iterator();
}

Object::const_iterator Object::cbegin() const
{
    return const_iterator();
}

Object::const_iterator Object::cend() const
{
    return const_iterator();
}

std::shared_ptr<Object> Object::getObject(const size_t id)
{
    (void)id;
    return nullptr;
}

void Object::add(std::shared_ptr<Object> obj)
{
    (void)obj;
}

void Object::remove(const size_t id)
{
    (void)id;
}
