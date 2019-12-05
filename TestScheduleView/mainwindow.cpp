#include "mainwindow.hpp"

#include <QStandardItemModel>
#include <QDebug>

#include "qxtscheduleview.h"
#include "qxtstyleoptionscheduleviewitem.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    view = new QxtScheduleView;
    view->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    model = new QStandardItemModel(10, 1, view);

    QDateTime time = QDateTime(QDate(2010, 1, 1), QTime(8, 0, 0));
    view->setDateRange(time.date(),time.date().addDays(6));

    for (int row = 0; row < 100; ++row) {
        int column = 0;
        QStandardItem *item = new QStandardItem(QString("row %0, column %1").arg(row).arg(column));

        item->setData(time.toTime_t(),Qxt::ItemStartTimeRole);
        item->setData(900*4,Qxt::ItemDurationRole);
        item->setData(QColor(qrand()%255,qrand()%255,qrand()%255),Qt::BackgroundRole);

        qDebug()<<"Data: "<<item->data(Qxt::ItemStartTimeRole);

        time = time.addSecs(900*2);

        model->setItem(row, column, item);
    }

    view->setModel(model);

    resize(1280, 1024);
    setCentralWidget(view);
}

MainWindow::~MainWindow()
{
}

