#ifndef DOORS_H
#define DOORS_H

#include "defines.h"

#include <QObject>
#include <QTimer>
#include <QDebug>

class Doors:public QObject
{
    Q_OBJECT

public:
    Doors(QObject *parent = nullptr);

signals:
    void doors_is_closed_signal();

public slots:
    void open_doors_slot();

private slots:
    void opened_doors_slot();
    void closed_doors_slot();

    void close_doors_slot();

private:
    enum doors_state_t
    {
        DOORS_OPENING = 0,
        DOORS_OPENED,
        DOORS_CLOSING,
        DOORS_CLOSED
    };

    doors_state_t state;

    QTimer open_doors_timer;
    QTimer close_doors_timer;
    QTimer wait_doors_timer;
};

#endif // DOORS_H
