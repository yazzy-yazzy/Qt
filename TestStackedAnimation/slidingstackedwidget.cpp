#include "slidingstackedwidget.hpp"

#include <QPropertyAnimation>
#include <QParallelAnimationGroup>

SlidingStackedWidget::SlidingStackedWidget(QWidget *parent) : QStackedWidget(parent)
{
    _mainwindow = (parent != nullptr ? parent : this);

    _vertical = false;
    _speed = 500;
//    _animationtype = QEasingCurve::OutBack;
    _animationtype = QEasingCurve::OutQuart;
    _now = 0;
    _next = 0;
    _wrap = false;
    _pnow = QPoint(0, 0);
    _active = false;
}

SlidingStackedWidget::~SlidingStackedWidget()
{

}

void SlidingStackedWidget::setSpeed(int speed)
{
    _speed = speed;
}

void SlidingStackedWidget::setAnimation(QEasingCurve::Type animationtype)
{
    _animationtype = animationtype;
}

void SlidingStackedWidget::setVerticalMode(bool vertical)
{
    _vertical = vertical;
}

void SlidingStackedWidget::setWrap(bool wrap)
{
    _wrap = wrap;
}

void SlidingStackedWidget::slideInNext()
{
    int now = currentIndex();
    if (_wrap || (now < count() - 1))
        slideInIdx(now + 1);
}

void SlidingStackedWidget::slideInPrev()
{
    int now = currentIndex();
    if (_wrap || (now > 0))
        slideInIdx(now - 1);
}

void SlidingStackedWidget::slideInIdx(int idx)
{
    if (idx > count() - 1)
        idx = idx % count();
    else if (idx < 0)
        idx = (idx + count()) % count();

    slideInWgt(widget(idx));
}

void SlidingStackedWidget::animationDoneSlot()
{
    setCurrentIndex(_next);
    widget(_now)->hide();
    widget(_now)->move(_pnow);
    _active = false;
    emit animationFinished();
}

void SlidingStackedWidget::slideInWgt(QWidget *newwidget)
{
    if (_active)
        return;

    _active = true;

    int now = currentIndex();
    int next = indexOf(newwidget);
    if (now == next) {
        _active = false;
        return;
    }

    int offsetx = frameRect().width();
    int offsety = frameRect().height();
    widget(next)->setGeometry(0,  0, offsetx, offsety);

//    offsetx = 0;    //Top -> Bottom
    offsety = 0;    //Left -> Right
//    offsety = -offsety;   // Bottom -> Top
//    offsetx = -offsetx;   // Right -> Left

    QPoint pnext = widget(next)->pos();
    QPoint pnow = widget(now)->pos();
    _pnow = pnow;
    widget(next)->move(pnext.x() - offsetx, pnext.y() - offsety);
    widget(next)->show();
    widget(next)->raise();

    QPropertyAnimation *animnow = new QPropertyAnimation(widget(now), "pos");
    animnow->setDuration(_speed);
    animnow->setEasingCurve(_animationtype);
    animnow->setStartValue(QPoint(pnow.x(), pnow.y()));
    animnow->setEndValue(QPoint(offsetx + pnow.x(), offsety + pnow.y()));
    QPropertyAnimation *animnext = new QPropertyAnimation(widget(next), "pos");
    animnext->setDuration(_speed);
    animnext->setEasingCurve(_animationtype);
    animnext->setStartValue(QPoint(-offsetx + pnext.x(), offsety + pnext.y()));
    animnext->setEndValue(QPoint(pnext.x(), pnext.y()));

    QParallelAnimationGroup *animgroup = new QParallelAnimationGroup;
    animgroup->addAnimation(animnow);
    animgroup->addAnimation(animnext);

    QObject::connect(animgroup, SIGNAL(finished()),this,SLOT(animationDoneSlot()));
    _next = next;
    _now = now;
    _active = true;

    animgroup->start();
}
