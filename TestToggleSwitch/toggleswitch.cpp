#include "toggleswitch.hpp"

#include <QPainter>
#include <QMouseEvent>
#include <QPropertyAnimation>
#include <QFont>
#include <QDebug>

/**
 * @see https://stackoverflow.com/questions/14780517/toggle-switch-in-qt/38102598
 */
ToggleSwitch::ToggleSwitch(QWidget *parent, int trackRadius, int thumbRadius)
    : QAbstractButton(parent),
      _trackRadius(trackRadius),
      _thumbRadius(thumbRadius)
{
    setCheckable(true);
    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    _margin = qMax(0, _thumbRadius - _trackRadius);
    _offsetBase = qMax(_thumbRadius, _trackRadius);
//    _offsetEnd = offsetEnd(true);
    _offset = _offsetBase;

    if (_thumbRadius > _trackRadius) {
//        _trackColor = trackColor(true);
//        _thumbColor = thumbColor(true);
//        _textColor = textColor(true);
        _trackOpacity = 0.5;
    } else {
//        _trackColor = trackColor(true);
//        _thumbColor = thumbColor(true);
//        _textColor = textColor(true);
        _trackOpacity = 1.0;
    }
}

int ToggleSwitch::offset()
{
    return _offset;
}

void ToggleSwitch::setOffset(int offset)
{
    qDebug() << __PRETTY_FUNCTION__ << offset;

    _offset = offset;
    update();
}

QSize ToggleSwitch::sizeHint() const
{
    return QSize(4 * _trackRadius + 2 * _margin, 2 * _trackRadius + 2 * _margin);
}

int ToggleSwitch::offsetEnd(bool b)
{
    return (b ? width() - _offsetBase : _offsetBase);
}

QBrush ToggleSwitch::trackColor(bool b)
{
    if (_thumbRadius > _trackRadius)
        return (b ? palette().highlight() : palette().dark());

    return (b ? palette().highlight() : palette().dark());
}

QBrush ToggleSwitch::thumbColor(bool b)
{
    if (_thumbRadius > _trackRadius)
        return (b ? palette().highlight() : palette().light());

    return (b ? palette().highlightedText() : palette().light());
}

QColor ToggleSwitch::textColor(bool b)
{
    if (_thumbRadius > _trackRadius)
        return (b ? palette().highlightedText().color() : palette().dark().color());

    return (b ? palette().highlight().color() : palette().dark().color());
}

void ToggleSwitch::resizeEvent(QResizeEvent *event)
{
    QAbstractButton::resizeEvent(event);
    _offset = offsetEnd(isChecked());
}

void ToggleSwitch::paintEvent(QPaintEvent* event)
{
    qDebug() << __PRETTY_FUNCTION__ << isChecked();
    Q_UNUSED(event)

    QPainter p(this);
    p.setRenderHint(QPainter::Antialiasing, true);
    p.setPen(Qt::NoPen);

    qreal trackOpacity = _trackOpacity;
    qreal thumbOpacity = 1.0;
//    qreal textOpacity = 1.0;

    QBrush trackBrush;
    QBrush thumbBrush;
    QColor text;

    if (isEnabled()) {
        trackBrush = trackColor(isChecked());
        thumbBrush = thumbColor(isChecked());
        text = textColor(isChecked());
    } else {
        trackOpacity *= 0.8;
        trackBrush = palette().shadow();
        thumbBrush = palette().mid();
        text = palette().shadow().color();
    }

    p.setBrush(trackBrush);
    p.setOpacity(trackOpacity);
    p.drawRoundedRect(
        _margin,
        _margin,
        width() - 2 * _margin,
        height() - 2 * _margin,
        _trackRadius,
        _trackRadius
    );
//    qDebug() << __PRETTY_FUNCTION__ << QRect(_margin, _margin, width() - 2 * _margin, height() - 2 * _margin) << QSize(_trackRadius, _trackRadius);
    p.setBrush(thumbBrush);
    p.setOpacity(thumbOpacity);
    p.drawEllipse(
        _offset - _thumbRadius,
        _offsetBase - _thumbRadius,
        2 * _thumbRadius,
        2 * _thumbRadius
    );
//    qDebug() << __PRETTY_FUNCTION__ << QRect(_offset - _thumbRadius, _offsetBase - _thumbRadius, 2 * _thumbRadius, 2 * _thumbRadius);
//    p.setPen(text);
//    p.setOpacity(textOpacity);

//    QFont font = p.font();
//    font.setPixelSize(1.5 * _thumbRadius);
//    p.setFont(font);
//    p.drawText(
//        QRectF(
//            _offset - _thumbRadius,
//            _offsetBase - _thumbRadius,
//            2 * _thumbRadius,
//            2 * _thumbRadius
//        ),
//        Qt::AlignCenter,
//        _thumbText[self.isChecked()],
//    );
}

void ToggleSwitch::mouseReleaseEvent(QMouseEvent *event)
{
    qDebug() << __PRETTY_FUNCTION__ << _offset << offsetEnd(isChecked());

    QAbstractButton::mouseReleaseEvent(event);

    if (event->button() == Qt::LeftButton) {
        QPropertyAnimation anim(this, "offset", this);
        anim.setDuration(60);
        anim.setStartValue(offset());
        anim.setEndValue(offsetEnd(isChecked()));
        anim.start();
    }
}

void ToggleSwitch::enterEvent(QEvent *event)
{
    setCursor(Qt::PointingHandCursor);
    QAbstractButton::enterEvent(event);
}
