#include "mainwindow.hpp"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton, &QPushButton::clicked, [=] (void) {
        if (ui->pushButton->isChecked()) {
            ui->statusbar->established(ui->lineEdit->text());
            ui->pushButton->setText("Terminate");
        } else {
            ui->statusbar->terminated();
            ui->pushButton->setText("Establish");
        }
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

