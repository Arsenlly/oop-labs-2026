#ifndef LIFTCONTROLLER_H
#define LIFTCONTROLLER_H

#include "defines.h"
#include "cabin.h"

#include <QObject>

#include <memory>
#include <vector>

class LiftController: public QObject
{
    Q_OBJECT
public:
    explicit LiftController(QObject *parent = nullptr);

signals:
    void floor_button_change_signal(size_t n_floor, dir_t dir, bool active_fl);
    void cabin_button_change_signal(size_t id_cabin, size_t n_floor, bool active_fl);

public slots:
    void call_floor_lift_slot(size_t n_floor, dir_t dir);
    void call_cabin_lift_slot(size_t id_cabin, size_t n_floor);

private:
    std::vector<std::unique_ptr<Cabin>> cabins;
};

#endif // LIFTCONTROLLER_H
