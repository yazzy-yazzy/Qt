#ifndef STATUSBAREX_HPP
#define STATUSBAREX_HPP

#include <QStatusBar>

class QLabel;

class StatusBarEx : public QStatusBar
{
    Q_OBJECT
public:
    explicit StatusBarEx(QWidget *parent = nullptr);

public slots:
    void established(const QString &remoteAddress);
    void terminated();

private:
    QLabel *_networkIcon;
    QLabel *_remoteAddress;
    QLabel *_secureIcon;
};

#endif // STATUSBAREX_HPP
