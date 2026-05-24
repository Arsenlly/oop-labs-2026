#ifndef DOORS_H
#define DOORS_H

#include "defines.h"

#include <QObject>
#include <QTimer>

class Doors:public QObject
{
    Q_OBJECT

public:
    Doors(QObject *parent = nullptr);

signals:
    void doors_is_closed_signal();
    void doors_is_opened_signal();

public slots:
    void open_doors_slot();
    void close_doors_slot();

private slots:
    void opened_doors_slot();
    void closed_doors_slot();

private:
    doors_state_t state;

    QTimer open_doors_timer;
    QTimer close_doors_timer;
};

#endif // DOORS_H
