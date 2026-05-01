#include "basecommand.h"

void BaseCommand::setManagers(BaseCommand::tm_ptr transformManager,
                              BaseCommand::dm_ptr drawManager,
                              BaseCommand::lm_ptr loadManager)
{
    _drawManager = drawManager;
    _loadManager = loadManager;
    _transformManager = transformManager;
}
