#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QGraphicsScene>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    QGraphicsScene *scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

