#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>

class QxtScheduleView;
class QStandardItemModel;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QxtScheduleView *view;
    QStandardItemModel *model;
};
#endif // MAINWINDOW_HPP
