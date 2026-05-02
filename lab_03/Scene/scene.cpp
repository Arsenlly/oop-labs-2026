#include "scene.h"

std::shared_ptr<Object> Scene::getObject(std::size_t id)
{
    return _objects.at(id);
}

void Scene::addObject(std::shared_ptr<Object> object)
{
    _objects.push_back(object);
}
