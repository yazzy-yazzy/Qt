#include "splitterex.hpp"

#include <QPainter>
#include <QPaintEvent>
#include <QDebug>

SplitterEx::SplitterEx(Qt::Orientation orientation, QWidget *parent) : QSplitter(orientation, parent)
{
}

SplitterEx::SplitterEx(QWidget *parent) : QSplitter(parent)
{
}

QSplitterHandle *SplitterEx::createHandle()
{
    new SplitterHandleEx(orientation(), this);
}

SplitterHandleEx::SplitterHandleEx(Qt::Orientation orientation, QSplitter *parent) : QSplitterHandle(orientation, parent)
{
}

QSize SplitterHandleEx::sizeHint() const
{
    QSize size = QSplitterHandle::sizeHint();
//    qDebug() << __PRETTY_FUNCTION__ << size;
    size.setWidth(QPixmap(":/icon/arrow-left").width());
    return size;
}

void SplitterHandleEx::mousePressEvent(QMouseEvent *event)
{
    Q_UNUSED(event)

    if (isCollapsed())
        splitter()->setSizes({1, 1});
    else
        splitter()->setSizes({0, 1});
}

void SplitterHandleEx::paintEvent(QPaintEvent *event)
{
    QPixmap pixmap = isCollapsed() ? QPixmap(":/icon/arrow-right") : QPixmap(":/icon/arrow-left");

    int w = pixmap.width();
    int h = pixmap.height();
    int x = (event->rect().width() / 2) - (w / 2);
    int y = (event->rect().height() / 2) - (h / 2);
    qDebug() << __PRETTY_FUNCTION__ << event->rect() << x << y << w << h;
    qDebug() << __PRETTY_FUNCTION__ << splitter()->contentsMargins();

    QPainter painter(this);
    painter.drawPixmap(x, y, w, h, pixmap);
}

bool SplitterHandleEx::isCollapsed() const
{
    return (splitter()->sizes().first() == 0);
}
