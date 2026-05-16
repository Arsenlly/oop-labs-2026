#include "drawmanager.h"

#include <iostream>

template<typename DrawerFactory, typename... Args>
requires NotAbstract<DrawerFactory> && Derivative<DrawerFactory, BaseDrawerFactory> && Constructible<DrawerFactory, Args...>
void DrawManager::DrawScene(std::shared_ptr<Scene> scene, std::shared_ptr<Camera> camera, Args... args)
{
    DrawerFactory drawerFactory(args...);

    std::shared_ptr<BaseDrawer> drawer = drawerFactory.createDrawer();

    DrawVisitor visitor(drawer, camera);

    for (auto it = scene->begin();it != scene->end();it++)
    {
        (*it)->accept(visitor);
    }
}
