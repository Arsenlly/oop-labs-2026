#include <QFileDialog>

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("3D-Viewer");

    QGraphicsScene *scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    //connect(ui->buttonRotate, &QPushButton::clicked, this, &MainWindow::on_buttonRotate_clicked);
    //connect(ui->buttonScale, &QPushButton::clicked, this, &MainWindow::on_buttonScale_clicked);
    //connect(ui->buttonMove, &QPushButton::clicked, this, &MainWindow::on_buttonMove_clicked);
    //connect(ui->buttonChooseFile, &QPushButton::clicked, this, &MainWindow::on_buttonChooseFile_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_buttonRotate_clicked()
{
}

void MainWindow::on_buttonScale_clicked()
{
}

void MainWindow::on_buttonMove_clicked()
{
}

void MainWindow::on_buttonChooseFile_clicked()
{
    QString path = QFileDialog::getOpenFileName();
}
