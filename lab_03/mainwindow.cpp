#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include "drawqtcommand.h"

#include "movemodelcommand.h"
#include "scalemodelcommand.h"
#include "rotatemodelcommand.h"

#include "loadmodelcommand.h"

#include "ids.h"

#include <string>
#include <filesystem>

#include <QGraphicsScene>
#include <QFileDialog>
#include <QMessageBox>
#include <QtMath>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->objectsTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->objectsTable->setFocusPolicy(Qt::NoFocus);
    ui->objectsTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->objectsTable->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->objectsTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    QGraphicsScene *scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::getSelectedObjects()
{
    auto selected = ui->objectsTable->selectedItems();

    selected_obj.clear();

    for (const auto el : selected)
    {
        if (el->column() == 0)
        {
            selected_obj.push_back(el->row());
        }
    }
}

void MainWindow::insertRowInObjTable(size_t id, const std::string &name, const Point &center)
{
    ui->objectsTable->insertRow(ui->objectsTable->rowCount());

    ui->objectsTable->setItem(ui->objectsTable->rowCount() - 1, 0,
                             new QTableWidgetItem{ QString::number(id) });

    ui->objectsTable->setItem(ui->objectsTable->rowCount() - 1, 1,
                             new QTableWidgetItem{ QString(name.c_str()) });

    ui->objectsTable->setItem(ui->objectsTable->rowCount() - 1, 2,
                             new QTableWidgetItem{ "(" + QString::number(center.getX()) + "; "
                                                  + QString::number(center.getY()) + "; "
                                                  + QString::number(center.getZ()) + ")" });
}

void MainWindow::drawScene()
{
    ui->graphicsView->scene()->clear();
    DRawQtCommand command(ui->graphicsView->scene());
    _facade.execute(command);
}

void MainWindow::on_move_button_clicked()
{
    double dx = ui->move_x_spin->value();
    double dy = ui->move_y_spin->value();
    double dz = ui->move_z_spin->value();

    getSelectedObjects();

    for (auto id : selected_obj)
    {
        MoveModelCommand move_command(id, dx, dy, dz);

        _facade.execute(move_command);
    }

    drawScene();
}



void MainWindow::on_scale_button_clicked()
{
    double kx = ui->scale_x_spin->value();
    double ky = ui->scale_y_spin->value();
    double kz = ui->scale_z_spin->value();

    getSelectedObjects();

    for (auto id : selected_obj)
    {
        ScaleModelCommand scale_command(id, kx, ky, kz);

        _facade.execute(scale_command);
    }

    drawScene();
}

void MainWindow::on_rotate_button_clicked()
{
    double x_angle = qDegreesToRadians(ui->rotate_x_spin->value());
    double y_angle = qDegreesToRadians(ui->rotate_y_spin->value());
    double z_angle = qDegreesToRadians(ui->rotate_z_spin->value());

    getSelectedObjects();

    for (auto id : selected_obj)
    {
        RotateModelCommand rotate_command(id, x_angle, y_angle, z_angle);

        _facade.execute(rotate_command);
    }

    drawScene();
}

void MainWindow::on_load_model_button_clicked()
{
    try
    {
        std::string filename = QFileDialog::getOpenFileName().toStdString();

        InternalReprId repr = ListRepr;
        if (ui->ListReprRadioButton->isChecked())
            repr = ListRepr;
        else if (ui->MatrixReprRadioButton->isChecked())
            repr = MatrixRepr;

        LoadModelCommand command(repr, filename);
        _facade.execute(command);

        // TODO
        insertRowInObjTable(cur_id++, std::filesystem::path(filename).filename(), Point(0,0,0));

        drawScene();
    }
    catch(const BaseException &ex)
    {
        QMessageBox::critical(this, "Error!", ex.what());
    }
    catch(const std::exception &ex)
    {
        QMessageBox::critical(this, "Unknown error!", ex.what());
    }
}

void MainWindow::on_add_camera_button_clicked()
{

}

void MainWindow::on_set_camera_button_clicked()
{

}
