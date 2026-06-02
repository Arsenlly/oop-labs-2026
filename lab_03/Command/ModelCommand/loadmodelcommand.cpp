#include "loadmodelcommand.h"

LoadModelCommand::LoadModelCommand(const InternalReprId repr_id, const std::string &filename)
{
    _filename = filename;
    _repr = repr_id;
}

void LoadModelCommand::execute()
{
    _loadManager->load(_sceneManager, _repr, _filename);
}
