#ifndef DIRECTORSOLUTION_H
#define DIRECTORSOLUTION_H

#include "ids.h"
#include "basedirector.h"
#include "concretedirectorcreator.h"
#include "skeletonmodeldirector.h"
#include "basedirectorcreator.h"

#include <map>
#include <memory>

class DirectorSolution
{
public:
    DirectorSolution();
    ~DirectorSolution() = default;

    void registerCreator(ModelDirectorId dir_id, std::shared_ptr<BaseDirectorCreator> new_creator);

    std::shared_ptr<BaseDirector> create(ModelDirectorId dir_id, std::shared_ptr<ModelReader> reader, InternalReprId repr_id);

private:
    std::map<ModelDirectorId, std::shared_ptr<BaseDirectorCreator>> _creators;
};

#endif // DIRECTORSOLUTION_H
