#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "error.h"
#include "transform.h"

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

private slots:
    void on_buttonRotate_clicked();
    void on_buttonScale_clicked();
    void on_buttonMove_clicked();
    void on_buttonChooseFile_clicked();
private:
    err_t draw();
    void read_move_data(move_t &move);
    void read_scale_data(scale_t &scale);
    void read_rotate_data(rotate_t &rotate);
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
