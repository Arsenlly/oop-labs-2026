#include "caretaker.h"

void CareTaker::saveState(size_t id, std::shared_ptr<Memento> memento)
{
    if (memento)
        _mementos[id].push_back(memento);
}

std::shared_ptr<Memento> CareTaker::getLastState(size_t id)
{
    auto it = _mementos.find(id);

    if (it != _mementos.end() && !it->second.empty())
    {
        auto memento = it->second.back();
        it->second.pop_back();
        return memento;
    }

    return nullptr;
}
