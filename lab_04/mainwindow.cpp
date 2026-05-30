#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "defines.h"

#include <QWidget>
#include <QHBoxLayout>
#include <QGroupBox>
#include <QLabel>
#include <QPushButton>
#include <QChar>

#include <iostream>

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
            auto up_button = new QPushButton("↑", this);
            up_button->setObjectName(QString("floor%1_up").arg(n_floor));

            up_button->setFixedSize(50, 50);
            up_button->setStyleSheet(
                "QPushButton {"
                "    background-color: #d0d0d0;"
                "    border: 2px solid #808080;"
                "    border-radius: 15px;"
                "    font-size: 20px;"
                "    color: #000000;"
                "    min-width: 50px;"
                "    min-height: 50px;"
                "    max-width: 50px;"
                "    max-height: 50px;"
                "}"
                "QPushButton:hover {"
                "    background-color: #b0b0b0;"
                "}"
                "QPushButton:pressed {"
                "    background-color: #909090;"
                "}"
                );

            floor_button_layout->addWidget(up_button, n_row, 1);

            QObject::connect(up_button, &QPushButton::clicked, this, [this, n_floor]() {
                elevator_system.call_floor_lift_slot(n_floor, DIR_UP);
            });
        }

        if (n_floor != 1)
        {
            auto down_button = new QPushButton("↓", this);
            down_button->setObjectName(QString("floor%1_down").arg(n_floor));

            down_button->setFixedSize(50, 50);
            down_button->setStyleSheet(
                "QPushButton {"
                "    background-color: #d0d0d0;"
                "    border: 2px solid #808080;"
                "    border-radius: 15px;"
                "    font-size: 20px;"
                "    color: #000000;"
                "    min-width: 50px;"
                "    min-height: 50px;"
                "    max-width: 50px;"
                "    max-height: 50px;"
                "}"
                "QPushButton:hover {"
                "    background-color: #b0b0b0;"
                "}"
                "QPushButton:pressed {"
                "    background-color: #909090;"
                "}"
                );

            floor_button_layout->addWidget(down_button, n_row, 2);

            QObject::connect(down_button, &QPushButton::clicked, this, [this, n_floor]() {
                elevator_system.call_floor_lift_slot(n_floor, DIR_DOWN);
            });
        }
    }


    auto lift_section = new QGroupBox();

    auto lift_layout = new QGridLayout(lift_section);

    for (size_t n_floor = N_FLOOR; n_floor >= 1;n_floor--)
    {
        size_t n_row = N_FLOOR - n_floor + 1;

        QString fl = "○";
        if (n_floor == 1)
            fl = "●";
        auto button = new QPushButton(QString("%1 %2").arg(n_floor).arg(fl), this);
        button->setObjectName(QString("cab_floor%1").arg(n_floor));

        button->setFixedSize(50, 50);
        button->setStyleSheet(
            "QPushButton {"
            "    background-color: #e0e0e0;"
            "    border: 2px solid #808080;"
            "    border-radius: 10px;"
            "    font-size: 16px;"
            "    font-weight: bold;"
            "    color: #000000;"
            "    min-width: 60px;"
            "    min-height: 40px;"
            "    margin: 2px;"
            "}"
            "QPushButton:hover {"
            "    background-color: #c0c0c0;"
            "    color: #000000;"
            "    border-color: #606060;"
            "}"
            "QPushButton:pressed {"
            "    background-color: #a0a0a0;"
            "}"
            );
        QObject::connect(button, &QPushButton::clicked, this, [this, n_floor]() {
            elevator_system.call_cabin_lift_slot(n_floor);
        });

        lift_layout->addWidget(button, n_row, 0);
    }

    lift_button_layout->addWidget(lift_section, 0, 0);

    layout_box->addWidget(floor_button_section);
    layout_box->addWidget(lift_button_section);

    layout->addWidget(main_widget);

    QObject::connect(&elevator_system, &ElevatorSystem::floor_button_change_signal, this, &MainWindow::floor_button_change_slot);
    QObject::connect(&elevator_system, &ElevatorSystem::cabin_button_change_signal, this, &MainWindow::cabin_button_change_slot);
    QObject::connect(&elevator_system, &ElevatorSystem::cabin_pos_change_signal, this, &MainWindow::cabin_pos_change_slot);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::floor_button_change_slot(size_t n_floor, dir_t dir, bool active_fl)
{
    QPushButton *button = nullptr;
    if (dir == DIR_UP)
    {
        button = findChild<QPushButton *>(QString("floor%1_up").arg(n_floor));
    }
    else if (dir == DIR_DOWN)
    {
        button = findChild<QPushButton *>(QString("floor%1_down").arg(n_floor));
    }

    if (button)
    {
        if (active_fl)
        {
            button->setStyleSheet(
                "QPushButton {"
                "    background-color: #404040;"
                "    border: 3px solid #202020;"
                "    border-radius: 15px;"
                "    font-size: 20px;"
                "    color: white;"
                "    min-width: 50px;"
                "    min-height: 50px;"
                "    max-width: 50px;"
                "    max-height: 50px;"
                "}"
                );
        }
        else
        {
            button->setStyleSheet(
                "QPushButton {"
                "    background-color: #d0d0d0;"
                "    border: 2px solid #808080;"
                "    border-radius: 15px;"
                "    font-size: 20px;"
                "    color: #000000;"
                "    min-width: 50px;"
                "    min-height: 50px;"
                "    max-width: 50px;"
                "    max-height: 50px;"
                "}"
                "QPushButton:hover {"
                "    background-color: #b0b0b0;"
                "}"
                "QPushButton:pressed {"
                "    background-color: #909090;"
                "}"
                );
        }
    }
    this->update();
}

void MainWindow::cabin_button_change_slot(size_t n_floor, bool active_fl)
{
    QPushButton *button = nullptr;

    button = findChild<QPushButton *>(QString("cab_floor%1").arg(n_floor));

    if (button)
    {
        if (active_fl)
        {
            button->setStyleSheet(
                "QPushButton {"
                "    background-color: #2c3e50;"
                "    border: 2px solid #1a252f;"
                "    border-radius: 10px;"
                "    font-size: 16px;"
                "    font-weight: bold;"
                "    color: #ecf0f1;"
                "    min-width: 60px;"
                "    min-height: 40px;"
                "    margin: 2px;"
                "}"
                );
        }
        else
        {
            button->setStyleSheet(
                "QPushButton {"
                "    background-color: #e0e0e0;"
                "    border: 2px solid #808080;"
                "    border-radius: 10px;"
                "    font-size: 16px;"
                "    font-weight: bold;"
                "    color: #000000;"
                "    min-width: 60px;"
                "    min-height: 40px;"
                "    margin: 2px;"
                "}"
                "QPushButton:hover {"
                "    background-color: #c0c0c0;"
                "    color: #000000;"
                "    border-color: #606060;"
                "}"
                "QPushButton:pressed {"
                "    background-color: #a0a0a0;"
                "}"
                );
        }
    }
    this->update();
}

void MainWindow::cabin_pos_change_slot(size_t n_floor)
{
    QPushButton *button = nullptr;

    for (size_t i = 0;i < N_FLOOR;i++)
    {
        button = findChild<QPushButton *>(QString("cab_floor%1").arg(i + 1));

        if (i + 1 != n_floor)
            button->setText(QString("%1 ○").arg(i + 1));
        else
            button->setText(QString("%1 ●").arg(i + 1));
    }

    this->update();
}
