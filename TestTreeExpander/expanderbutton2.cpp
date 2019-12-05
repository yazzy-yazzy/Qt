#include "expanderbutton2.hpp"

#include <QHBoxLayout>
#include <QLabel>
#include <QIcon>
#include <QMouseEvent>
#include <QTreeWidget>
#include <QTreeWidgetItem>

ExpanderButton2::ExpanderButton2(const QString &text, QTreeWidget *parent, QTreeWidgetItem *item)
    : QFrame(parent), _item(item)
{
    setFrameStyle(QFrame::StyledPanel | QFrame::Plain);
    setLineWidth(1);

    QLabel *iconLabel = new QLabel;
    iconLabel->setFixedSize(64, 64);
    iconLabel->setPixmap(QPixmap(":/icon/clock"));
    iconLabel->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    QLabel *textLabel = new QLabel;
    textLabel->setText(text);
    textLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);

    _arrow = new QLabel;
    _arrow->setFixedSize(16, 16);
    _arrow->setPixmap(QPixmap(":/icon/arrow-down"));
    _arrow->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(iconLabel);
    layout->addWidget(textLabel);
    layout->addWidget(_arrow);

    setLayout(layout);
}

void ExpanderButton2::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        _item->setExpanded(!_item->isExpanded());
        _arrow->setPixmap(_item->isExpanded() ? QPixmap(":/icon/arrow-up") : QPixmap(":/icon/arrow-down"));

        event->accept();
    }
}
