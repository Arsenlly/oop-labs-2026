#ifndef OBJECT_H
#define OBJECT_H

#include "visitor.h"

#include <map>
#include <memory>

class Object;
using objects_map = std::map<size_t, std::shared_ptr<Object>>;

class Object
{
    public:
        using iterator = objects_map::iterator;
        using const_iterator = objects_map::const_iterator;

    public:
        Object() = default;
        virtual ~Object() = 0;

        virtual iterator begin();
        virtual iterator end();

        virtual const_iterator begin() const;
        virtual const_iterator end() const;

        virtual const_iterator cbegin() const;
        virtual const_iterator cend() const;

        virtual std::shared_ptr<Object> getObject(const size_t id);
        virtual void add(std::shared_ptr<Object> obj);
        virtual void remove(const size_t id);

        virtual bool isVisible() const noexcept = 0;
        virtual bool isComposite() const noexcept = 0;

        virtual void accept(const Visitor &visitor) = 0;
};

#endif // OBJECT_H
