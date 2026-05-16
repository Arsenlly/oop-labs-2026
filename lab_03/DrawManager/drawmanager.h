#ifndef DRAWMANAGER_H
#define DRAWMANAGER_H

#include "scene.h"
#include "camera.h"
#include "concepts.h"
#include "basedrawerfactory.h"
#include "drawvisitor.h"

#include <memory>

class DrawManager
{
    public:
        DrawManager() = default;

        ~DrawManager() = default;

        template<typename DrawerFactory, typename... Args>
        requires NotAbstract<DrawerFactory> && Derivative<DrawerFactory, BaseDrawerFactory> && Constructible<DrawerFactory, Args...>
        void DrawScene(std::shared_ptr<Scene> scene, std::shared_ptr<Camera> camera, Args... args);
};

#include "drawmanager.hpp"

#endif // DRAWMANAGER_H
