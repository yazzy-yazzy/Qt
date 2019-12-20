#include "dialog.hpp"

#include <QVBoxLayout>
#include <QPushButton>

#include "switchbutton.hpp"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    QPushButton *pushButton = new QPushButton;
    SwitchButton *switchButton = new SwitchButton(nullptr, SwitchButton::Style::EMPTY);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(pushButton);
    layout->addWidget(switchButton);

    setLayout(layout);
    resize(240, 320);
}

Dialog::~Dialog()
{
}

