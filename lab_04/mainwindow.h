#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>

#include "elevatorsystem.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void floor_button_change_slot(size_t n_floor, dir_t dir, bool active_fl);
    void cabin_button_change_slot(size_t n_floor, bool active_fl);
    void cabin_pos_change_slot(size_t n_floor);

private:
    Ui::MainWindow *ui;
    QVBoxLayout *layout;

    ElevatorSystem elevator_system;
};
#endif // MAINWINDOW_H
