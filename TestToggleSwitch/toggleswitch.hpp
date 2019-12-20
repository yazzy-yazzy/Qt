#ifndef TOGGLESWITCH_HPP
#define TOGGLESWITCH_HPP

#include <QAbstractButton>
#include <QBrush>
#include <QColor>

class ToggleSwitch : public QAbstractButton
{
    Q_OBJECT
    Q_PROPERTY(int offset READ offset WRITE setOffset)

public:
    explicit ToggleSwitch(QWidget *parent = nullptr, int trackRadius = 10, int thumbRadius = 8);
    QSize sizeHint() const override;

//public slots:
//    void setChecked(bool) override;

protected:
    void paintEvent(QPaintEvent *e) override;
    void enterEvent(QEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;

private:
    void setOffset(int offset);
    int offset();
    int offsetEnd(bool b);
    QBrush trackColor(bool b);
    QBrush thumbColor(bool b);
    QColor textColor(bool b);

    int _trackRadius;
    int _thumbRadius;
    int _margin;
    int _offset;
    int _offsetBase;
    int _offsetEnd;

    QBrush _trackColor;
    QBrush _thumbColor;
    QColor _textColor;
    qreal _trackOpacity;
};

#endif // TOGGLESWITCH_HPP
