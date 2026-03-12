#include <QFileDialog>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "request.h"
#include "error.h"
#include "math_utils.h"
#include "qt_draw.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("3D-Viewer");

    QGraphicsScene *scene = new QGraphicsScene(this);
    scene->setSceneRect(-610, -440, 1220, 880);
    ui->graphicsView->setScene(scene);
}

MainWindow::~MainWindow()
{
    request_t request;

    request.type_request = EXIT;
    handle_request(request);
    delete ui;
}

err_t MainWindow::draw()
{
    request_t request;
    request.type_request = DRAW;

    init_draw_field(request.draw_field, ui->graphicsView->scene());

    err_t rc = handle_request(request);
    return rc;
}

void MainWindow::read_move_data(move_t &move)
{
    move.dx = ui->move_x->value();
    move.dy = ui->move_y->value();
    move.dz = ui->move_z->value();
}

void MainWindow::read_scale_data(scale_t &scale)
{
    scale.kx = ui->scale_x->value();
    scale.ky = ui->scale_y->value();
    scale.kz = ui->scale_z->value();
}

void MainWindow::read_rotate_data(rotate_t &rotate)
{
    rotate.x_angle = to_radians(ui->rotate_x->value());
    rotate.y_angle = to_radians(ui->rotate_y->value());
    rotate.z_angle = to_radians(ui->rotate_z->value());
}

void MainWindow::on_buttonRotate_clicked()
{
    request_t request;

    request.type_request = ROTATE;
    read_rotate_data(request.rotate);

    err_t rc = handle_request(request);

    if (rc)
        error_message(rc);
    else
    {
        rc = draw();
        if (rc)
            error_message(rc);
    }
}

void MainWindow::on_buttonScale_clicked()
{
    request_t request;

    request.type_request = SCALE;
    read_scale_data(request.scale);

    err_t rc = handle_request(request);

    if (rc)
        error_message(rc);
    else
    {
        rc = draw();
        if (rc)
            error_message(rc);
    }
}

void MainWindow::on_buttonMove_clicked()
{
    request_t request;

    request.type_request = MOVE;
    read_move_data(request.move);

    err_t rc = handle_request(request);

    if (rc)
        error_message(rc);
    else
    {
        rc = draw();
        if (rc)
            error_message(rc);
    }
}

void MainWindow::on_buttonChooseFile_clicked()
{
    request_t request;

    QString path = QFileDialog::getOpenFileName();
    QByteArray ba = path.toLocal8Bit();

    request.type_request = LOAD;
    request.filename = ba.data();

    err_t rc = handle_request(request);

    if (rc)
        error_message(rc);
    else
    {
        rc = draw();
        if (rc)
            error_message(rc);
    }
}
