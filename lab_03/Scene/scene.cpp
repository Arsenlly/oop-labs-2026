#include "scene.h"

std::shared_ptr<Object> Scene::getObject(std::size_t id)
{
    return _objects.at(id);
}

void Scene::addObject(std::shared_ptr<Object> object)
{
    _objects[cur_id++] = object;
}

void Scene::removeObject(size_t id)
{
    _objects.erase(id);
}

Scene::iterator Scene::begin()
{
    return _objects.begin();
}

Scene::iterator Scene::end()
{
    return _objects.end();
}

Scene::const_iterator Scene::begin() const
{
    return _objects.cbegin();
}

Scene::const_iterator Scene::end() const
{
    return _objects.cend();
}

Scene::const_iterator Scene::cbegin() const
{
    return _objects.cbegin();
}

Scene::const_iterator Scene::cend() const
{
    return _objects.cend();
}
