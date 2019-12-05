#ifndef SLIDINGSTACKEDWIDGET_HPP
#define SLIDINGSTACKEDWIDGET_HPP

#include <QStackedWidget>
#include <QEasingCurve>

class SlidingStackedWidget : public QStackedWidget
{
    Q_OBJECT
public:
    explicit SlidingStackedWidget(QWidget *parent = nullptr);
    ~SlidingStackedWidget();

signals:
    void animationFinished(void);

public slots:
    void setSpeed(int speed);
    void setAnimation(enum QEasingCurve::Type animationtype);
    void setVerticalMode(bool vertical=true);
    void setWrap(bool wrap);

    void slideInNext();
    void slideInPrev();
    void slideInIdx(int idx);

protected slots:
    void animationDoneSlot(void);

protected:
     void slideInWgt(QWidget * widget);

private:
    QWidget *_mainwindow;
    int _speed;
    enum QEasingCurve::Type _animationtype;
    bool _vertical;
    int _now;
    int _next;
    bool _wrap;
    QPoint _pnow;
    bool _active;
};

#endif // SLIDINGSTACKEDWIDGET_HPP
