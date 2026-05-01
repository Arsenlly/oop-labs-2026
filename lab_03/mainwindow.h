#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "scenefacade.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_move_model_button_clicked();
    void on_move_camera_button_clicked();
    void on_move_everything_button_clicked();

    void on_scale_model_button_clicked();
    void on_scale_everything_button_clicked();

    void on_rotate_model_button_clicked();
    void on_rotate_everything_button_clicked();

private:
    Ui::MainWindow *ui;
    SceneFacade _facade;
};
#endif // MAINWINDOW_H
