#include "scenefacade.h"

void SceneFacade::execute(BaseCommand &command)
{
    command.setManagers(_transformManager, _drawManager, _loadManager);
    command.execute();
}
