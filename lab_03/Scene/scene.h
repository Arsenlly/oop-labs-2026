#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include <memory>
#include <cstddef>

#include "object.h"

class Scene
{
public:
    Scene() = default;
    ~Scene() = default;

    std::shared_ptr<Object> getObject(std::size_t id);
    void addObject(std::shared_ptr<Object> object);

private:
    std::vector<std::shared_ptr<Object>> _objects;
};


#endif // SCENE_H
