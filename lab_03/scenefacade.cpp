#include "scenefacade.h"

void SceneFacade::execute(BaseCommand &command)
{
    command.execute();
}
