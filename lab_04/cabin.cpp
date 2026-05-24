#include "cabin.h"

Cabin::Cabin(QObject *parent):
    QObject(parent),
    state(CABIN_FREE)
{
    QObject::connect(this, &Cabin::open_doors_signal, &cabin_doors, &Doors::open_doors_slot);
    QObject::connect(this, &Cabin::close_doors_signal, &cabin_doors, &Doors::close_doors_slot);
}
