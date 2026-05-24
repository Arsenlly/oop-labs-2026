#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "defines.h"

#include <QWidget>
#include <QHBoxLayout>
#include <QGroupBox>
#include <QLabel>
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , layout(new QVBoxLayout())
{
    ui->setupUi(this);

    ui->centralwidget->setLayout(layout);

    auto main_widget = new QWidget();
    auto layout_box = new QHBoxLayout(main_widget);
    layout_box->setSpacing(50);

    auto floor_button_section = new QGroupBox();
    auto lift_button_section = new QGroupBox();

    auto floor_button_layout = new QGridLayout(floor_button_section);
    auto lift_button_layout = new QGridLayout(lift_button_section);

    for (size_t n_floor = N_FLOOR; n_floor >= 1;n_floor--)
    {
        size_t n_row = N_FLOOR - n_floor + 1;

        auto floor_label = new QLabel(QString("Этаж %1").arg(n_floor));
        floor_label->setAlignment(Qt::AlignCenter);

        floor_button_layout->addWidget(floor_label, n_row, 0);

        if (n_floor != N_FLOOR)
        {
            auto up_button = new QPushButton("↑");

            up_button->setFixedSize(50, 50);
            up_button->setStyleSheet(
                "QPushButton {"
                "    background-color: #d0d0d0;"
                "    border-radius: 25px;"
                "    border: 2px solid #808080;"
                "    font-size: 20px;"
                "}"
                );

            floor_button_layout->addWidget(up_button, n_row, 1);

            // TODO добавить connect
        }

        if (n_floor != 1)
        {
            auto down_button = new QPushButton("↓");

            down_button->setFixedSize(50, 50);
            down_button->setStyleSheet(
                "QPushButton {"
                "    background-color: #d0d0d0;"
                "    border-radius: 25px;"
                "    border: 2px solid #808080;"
                "    font-size: 20px;"
                "}"
                );

            floor_button_layout->addWidget(down_button, n_row, 2);

            // TODO добавить connect
        }
    }

    for (size_t n_lift = 0; n_lift < N_ELEVATOR;n_lift++)
    {
        auto lift_section = new QGroupBox();

        auto lift_layout = new QGridLayout(lift_section);

        for (size_t n_floor = N_FLOOR; n_floor >= 1;n_floor--)
        {
            size_t n_row = N_FLOOR - n_floor + 1;

            auto button = new QPushButton(QString("%1").arg(n_floor));

            button->setFixedSize(50, 50);
            button->setStyleSheet(
                "QPushButton {"
                "    background-color: #d0d0d0;"
                "    border-radius: 25px;"
                "    border: 2px solid #808080;"
                "    font-size: 20px;"
                "}"
                );

            // TODO добавить connect

            lift_layout->addWidget(button, n_row, 0);
        }

        lift_button_layout->addWidget(lift_section, 0, n_lift);
    }

    layout_box->addWidget(floor_button_section);
    layout_box->addWidget(lift_button_section);

    layout->addWidget(main_widget);

    QObject::connect(&elevator_system, &ElevatorSystem::floor_button_change_signal, this, &MainWindow::floor_button_change_slot);
    QObject::connect(&elevator_system, &ElevatorSystem::cabin_button_change_signal, this, &MainWindow::cabin_button_change_slot);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::floor_button_change_slot(size_t n_floor, dir_t dir, bool active_fl)
{

}

void MainWindow::cabin_button_change_slot(size_t id_cabin, size_t n_floor, bool active_fl)
{

}
