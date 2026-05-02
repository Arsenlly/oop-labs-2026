#ifndef BASECOMMAND_H
#define BASECOMMAND_H

#include "./TransformManager/transformmanager.h"
#include "./DrawManager/drawmanager.h"
#include "./LoadManager/loadmanager.h"

#include <memory>

class BaseCommand
{
public:
    using tm_ptr = std::shared_ptr<TransformManager>;
    using lm_ptr = std::shared_ptr<LoadManager>;
    using dm_ptr = std::shared_ptr<DrawManager>;

public:
    BaseCommand() = default;
    virtual ~BaseCommand() = default;

    virtual void execute() = 0;
    void setManagers(tm_ptr transformManager, dm_ptr drawManager, lm_ptr loadManager);

protected:
    tm_ptr _transformManager;
    dm_ptr _drawManager;
    lm_ptr _loadManager;
};

#endif // BASECOMMAND_H
