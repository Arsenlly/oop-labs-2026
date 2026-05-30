#ifndef LIFTCONTROLLER_H
#define LIFTCONTROLLER_H

#include "defines.h"
#include "cabin.h"

#include <QObject>
#include <QDebug>

#include <memory>
#include <vector>

class LiftController: public QObject
{
    Q_OBJECT
public:
    explicit LiftController(QObject *parent = nullptr);

signals:
    void floor_button_change_signal(size_t n_floor, dir_t dir, bool active_fl);
    void cabin_button_change_signal(size_t n_floor, bool active_fl);
    void cabin_pos_change_signal(size_t n_floor);

    void start_processing_signal(size_t floor);
    void free_controller_signal();
    void start_moving_signal();
    void start_boarding_signal();

    void cabin_start_boarding_signal();
    void cabin_move_up_signal();
    void cabin_move_down_signal();

public slots:
    void start_processing_slot(size_t floor);

private slots:
    void start_moving_slot();
    void free_controller_slot();
    void start_boarding_slot();

public:
    void call_floor_lift(size_t n_floor, dir_t dir);
    void call_cabin_lift(size_t n_floor);

private:
    void add_floor_order(size_t floor, dir_t dir);
    void add_cabin_order(size_t floor);

    void remove_order_on_cur_floor();

    int find_next_target();

private:
    enum con_state_t
    {
        CON_FREE = 0,
        CON_PROC,
        CON_MOVING,
        CON_BOARDING
    };

    con_state_t state;

    Cabin cabin;

    std::vector<floor_order_t> floor_orders;
    std::vector<bool> cabin_orders;

    size_t cur_floor = 0;
    dir_t cur_dir;
};

#endif // LIFTCONTROLLER_H
