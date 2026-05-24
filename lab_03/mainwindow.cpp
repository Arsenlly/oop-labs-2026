#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include "drawqtcommand.h"

#include "moveobjectcommand.h"
#include "scaleobjectcommand.h"
#include "rotateobjectcommand.h"

#include "loadmodelcommand.h"

#include "removeobjectcommand.h"

#include "addcameracommand.h"
#include "setactivecameracommand.h"

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
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    int w = ui->graphicsView->width();
    int h = ui->graphicsView->height();

    scene->setSceneRect(-w/2, -h/2, w, h);


    AddCameraCommand add_camera_command(Point(0, 0, -10));

    _facade.execute(add_camera_command);
    insertRowInObjTable(cur_id++, "Camera");

    SetActiveCameraCommand set_active_cam_command(cur_id - 1);

    _facade.execute(set_active_cam_command);
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
            size_t id = ui->objectsTable->item(el->row(), 0)->text().toULong();
            selected_obj.push_back(id);
        }
    }
}

void MainWindow::insertRowInObjTable(size_t id, const std::string &name)
{
    ui->objectsTable->insertRow(ui->objectsTable->rowCount());

    ui->objectsTable->setItem(ui->objectsTable->rowCount() - 1, 0,
                             new QTableWidgetItem{ QString::number(id) });

    ui->objectsTable->setItem(ui->objectsTable->rowCount() - 1, 1,
                             new QTableWidgetItem{ QString(name.c_str()) });
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

        insertRowInObjTable(cur_id++, std::filesystem::path(filename).filename());

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
    AddCameraCommand add_camera_command(Point(0, 0, -10));

    _facade.execute(add_camera_command);

    insertRowInObjTable(cur_id++, "Camera");
}

void MainWindow::on_set_camera_button_clicked()
{
    getSelectedObjects();

    if (selected_obj.size() != 1)
        QMessageBox::critical(this, "Error!", "Select 1 camera!");
    else
    {
        SetActiveCameraCommand command(selected_obj[0]);
        _facade.execute(command);

        drawScene();
    }
}

void MainWindow::on_delete_object_button_clicked()
{
    getSelectedObjects();

    try
    {
        for (auto id : selected_obj)
        {
            RemoveObjectCommand remove_command(id);

            _facade.execute(remove_command);

            int row = -1;
            for (int i = 0; i < ui->objectsTable->rowCount(); ++i)
            {
                size_t tableId = ui->objectsTable->item(i, 0)->text().toULong();
                if (tableId == id)
                {
                    row = i;
                    break;
                }
            }

            if (row != -1)
                ui->objectsTable->removeRow(row);
        }
    }
    catch(const BaseException &ex)
    {
        QMessageBox::critical(this, "Error!", ex.what());
    }
    catch(const std::exception &ex)
    {
        QMessageBox::critical(this, "Unknown error!", ex.what());
    }

    drawScene();
}
