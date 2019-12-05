#include "statusbarex.hpp"

#include <QLabel>
#include <QVariant>

StatusBarEx::StatusBarEx(QWidget *parent) : QStatusBar(parent)
{
    _networkIcon = new QLabel;
    _networkIcon->setFixedSize(32, 32);
    _networkIcon->setScaledContents(true);
    _networkIcon->setPixmap(QPixmap(":/icon/network-offline"));
    _networkIcon->setToolTip("オフライン");

    _remoteAddress = new QLabel;
    _remoteAddress->setText("未接続");
    _remoteAddress->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
    _remoteAddress->setMinimumWidth(180);

    _secureIcon = new QLabel;
    _secureIcon->setFixedSize(32, 32);
    _secureIcon->setScaledContents(true);
    _secureIcon->setPixmap(QPixmap(":/icon/security-high"));
    _secureIcon->setToolTip("高");

    addPermanentWidget(new QWidget(), 2);
    addPermanentWidget(_secureIcon);
    addPermanentWidget(_remoteAddress, 1);
    addPermanentWidget(_networkIcon);
}

void StatusBarEx::established(const QString &remoteAddress)
{
    _networkIcon->setPixmap(QPixmap(":/icon/network-active"));
    _networkIcon->setToolTip("オンライン");

    _remoteAddress->setText(remoteAddress);

    _secureIcon->setPixmap(QPixmap(":/icon/security-high"));
    _secureIcon->setToolTip("高");
}

void StatusBarEx::terminated()
{
    _networkIcon->setPixmap(QPixmap(":/icon/network-offline"));
    _networkIcon->setToolTip("オフライン");

    _remoteAddress->setText("未接続");

    _secureIcon->setPixmap(QPixmap());
    _secureIcon->setToolTip("");
}
