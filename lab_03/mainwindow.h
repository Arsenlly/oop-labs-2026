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
    void drawScene();

    void on_move_button_clicked();

    void on_scale_button_clicked();

    void on_rotate_button_clicked();

    void on_load_model_button_clicked();

    void on_add_camera_button_clicked();

    void on_set_camera_button_clicked();

    void getSelectedObjects();
    void insertRowInObjTable(size_t id, const std::string &name, const Point &center);


private:
    Ui::MainWindow *ui;
    SceneFacade _facade;

    std::vector<size_t> selected_obj;
};
#endif // MAINWINDOW_H
