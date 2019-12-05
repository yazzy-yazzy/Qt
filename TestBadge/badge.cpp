#include "badge.hpp"

#include <QPainter>
#include <QDebug>

Badge::Badge(const QString &text, QWidget *parent, Qt::WindowFlags f) : QLabel(text, parent, f)
{
    setup();
}

Badge::Badge(QWidget *parent, Qt::WindowFlags f) : QLabel(parent, f)
{
    setup();
}

void Badge::setup()
{
}

QSize Badge::sizeHint() const
{
    qDebug() << __PRETTY_FUNCTION__;

    QSize size = QLabel::sizeHint();
    qDebug() << __PRETTY_FUNCTION__ << size;

    size.setWidth(size.width() + 8);
    size.setHeight(size.height() + 4);

    qDebug() << __PRETTY_FUNCTION__ << size;
    return size;
}

void Badge::setNumber(int n)
{
    qDebug() << __PRETTY_FUNCTION__ << n;
    setText(QString::number(n));
}

void Badge::paintEvent(QPaintEvent *event)
{
//    int r = qMin(rect().width(), rect().height());
//    int x = (rect().width() - r) / 2;
//    int y = (rect().height() - r) / 2 + 1;

//    QRect rc(x, y, r, r);
//    qDebug() << __PRETTY_FUNCTION__ << rect() << rc;
    QRect rc(rect());

    QPainter p(this);
    p.setRenderHint(QPainter::Antialiasing);

    QPainterPath path;
    path.addRoundedRect(rc, 10, 10);

//    QPen pen(Qt::darkGray, 1);
//    p.setPen(pen);
    p.fillPath(path, Qt::gray);
//    p.drawPath(path);

    QLabel::paintEvent(event);
}
