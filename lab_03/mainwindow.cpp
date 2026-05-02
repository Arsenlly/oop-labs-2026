#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include "movemodelcommand.h"
#include "scalemodelcommand.h"
#include "rotatemodelcommand.h"

#include <QGraphicsScene>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QGraphicsScene *scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_move_model_button_clicked()
{
    double dx = ui->move_x_spin->value();
    double dy = ui->move_y_spin->value();
    double dz = ui->move_z_spin->value();

    size_t id = 0; // TODO

    MoveModelCommand move_command(id, dx, dy, dz);

    _facade.execute(move_command);

    // TODO отрисовка сцены
}

void MainWindow::on_move_camera_button_clicked()
{

}

void MainWindow::on_move_everything_button_clicked()
{

}

void MainWindow::on_scale_model_button_clicked()
{
    double kx = ui->scale_x_spin->value();
    double ky = ui->scale_y_spin->value();
    double kz = ui->scale_z_spin->value();

    size_t id = 0; // TODO

    ScaleModelCommand scale_command(id, kx, ky, kz);

    _facade.execute(scale_command);

    // TODO отрисовка сцены
}

void MainWindow::on_scale_everything_button_clicked()
{

}

void MainWindow::on_rotate_model_button_clicked()
{
    // TODO перевод в радианы
    double x_angle = ui->rotate_x_spin->value();
    double y_angle = ui->rotate_y_spin->value();
    double z_angle = ui->rotate_z_spin->value();

    size_t id = 0; // TODO

    RotateModelCommand rotate_command(id, x_angle, y_angle, z_angle);

    _facade.execute(rotate_command);

    // TODO отрисовка сцены
}

void MainWindow::on_rotate_everything_button_clicked()
{

}
