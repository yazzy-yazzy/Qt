#include "mainwindow.hpp"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//    connect(ui->aaaButton, &QPushButton::clicked, [=]{
//        ui->stackedWidget->setCurrentIndex(1);
//    });
//    connect(ui->bbbButton, &QPushButton::clicked, [=]{
//        ui->stackedWidget->setCurrentIndex(0);
//    });

    connect(ui->aaaButton, &QPushButton::clicked, [=]{
        ui->stackedWidget->slideInIdx(1);
    });
    connect(ui->bbbButton, &QPushButton::clicked, [=]{
        ui->stackedWidget->slideInIdx(0);
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

