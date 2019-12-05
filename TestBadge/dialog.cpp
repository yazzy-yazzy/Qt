#include "dialog.hpp"
#include "ui_dialog.h"

#include <QStringListModel>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    QStringList list;
    list << "aaa" << "bbb" << "ccc";

    ui->listView->setModel(new QStringListModel(list));

//    ui->badge->setNumber(ui->listView->model()->rowCount());
    ui->badge->setNumber(100000);
}

Dialog::~Dialog()
{
    delete ui;
}

