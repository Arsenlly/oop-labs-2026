#ifndef SCENE_H
#define SCENE_H

#include <map>
#include <memory>
#include <cstddef>

#include "object.h"

class Scene
{
public:
    using iterator = std::map<size_t, std::shared_ptr<Object>>::iterator;
    using const_iterator = std::map<size_t, std::shared_ptr<Object>>::const_iterator;
    using size_type = std::map<size_t, std::shared_ptr<Object>>::size_type;
public:
    Scene() = default;
    ~Scene() = default;

    std::shared_ptr<Object> getObject(std::size_t id);
    void addObject(std::shared_ptr<Object> object);
    void removeObject(size_t id);

    iterator begin();
    iterator end();

    const_iterator begin() const;
    const_iterator end() const;

    const_iterator cbegin() const;
    const_iterator cend() const;

private:
    std::map<size_t, std::shared_ptr<Object>> _objects;
    size_t cur_id = 0;
};


#endif // SCENE_H
