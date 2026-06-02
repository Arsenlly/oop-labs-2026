#ifndef CARETAKER_H
#define CARETAKER_H

#include "memento.h"

#include <memory>
#include <vector>
#include <map>

class CareTaker
{
public:
    CareTaker() = default;
    ~CareTaker() = default;

    void saveState(size_t id, std::shared_ptr<Memento> memento);
    std::shared_ptr<Memento> getLastState(size_t id);

private:
    std::map<size_t, std::vector<std::shared_ptr<Memento>>> _mementos;
};

#endif // CARETAKER_H
