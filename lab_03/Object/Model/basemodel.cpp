#include "basemodel.h"

BaseModel::BaseModel(std::shared_ptr<ModelStructure> structure)
{
    _structure = structure;
}

BaseModel::~BaseModel() {}

std::shared_ptr<ModelStructure> BaseModel::getStructure()
{
    return _structure;
}
