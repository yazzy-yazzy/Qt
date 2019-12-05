#ifndef BADGE_HPP
#define BADGE_HPP

#include <QLabel>

class Badge : public QLabel
{
    Q_OBJECT
public:
    Badge(const QString &text, QWidget *parent = nullptr, Qt::WindowFlags f = Qt::WindowFlags());
    Badge(QWidget *parent = nullptr, Qt::WindowFlags f = Qt::WindowFlags());

    void setNumber(int n);

    QSize sizeHint() const override;

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    void setup();
};

#endif // BADGE_HPP
