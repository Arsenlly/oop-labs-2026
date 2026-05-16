#ifndef LOADMANAGER_H
#define LOADMANAGER_H

#include "readersolution.h"
#include "modelreader.h"
#include "listmodelbuilder.h"
#include "skeletonmodeldirector.h"
#include "ids.h"
#include "buildersolution.h"

#include <string>
#include <memory>

class LoadManager
{
    public:
        LoadManager();

        std::shared_ptr<Object> load(InternalReprId repr_id, const std::string &filename);

    private:
        std::shared_ptr<ReaderSolution> rsol;
        std::shared_ptr<BuilderSolution> bsol;
};

#endif // LOADMANAGER_H
