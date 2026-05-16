#include "loadmodelcommand.h"

LoadModelCommand::LoadModelCommand(const InternalReprId repr_id, const std::string &filename)
{
    _filename = filename;
    _repr = repr_id;
}

void LoadModelCommand::execute()
{
    std::shared_ptr<Object> obj = _loadManager->load(_repr, _filename);

    _sceneManager->addObject(obj);
}
