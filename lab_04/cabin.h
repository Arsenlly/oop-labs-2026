#ifndef CABIN_H
#define CABIN_H

#include "doors.h"
#include "defines.h"

#include <QObject>

class Cabin: public QObject
{
    Q_OBJECT

public:
    Cabin(QObject *parent = nullptr);

signals:
    void open_doors_signal();
    void close_doors_signal();

public slots:
    void doors_is_opened_slot();
    void doors_is_closed_slot();

private:
    Doors cabin_doors;

    cabin_state_t state;
};

#endif // CABIN_H
