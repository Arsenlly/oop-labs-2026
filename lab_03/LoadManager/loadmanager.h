#ifndef LOADMANAGER_H
#define LOADMANAGER_H

#include <string>

class LoadManager
{
    public:
        LoadManager();

        void load(const std::string &filename);
};

#endif // LOADMANAGER_H
