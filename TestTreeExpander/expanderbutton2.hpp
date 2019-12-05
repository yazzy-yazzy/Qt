#ifndef EXPANDERBUTTON2_HPP
#define EXPANDERBUTTON2_HPP

#include <QFrame>

class QLabel;
class QTreeWidget;
class QTreeWidgetItem;

class ExpanderButton2 : public QFrame
{
    Q_OBJECT
public:
    ExpanderButton2(const QString &text, QTreeWidget *parent, QTreeWidgetItem *item);

signals:

public slots:

protected:
    void mousePressEvent(QMouseEvent *event) override;

private:
    QTreeWidgetItem *_item;
    QLabel *_arrow;
};

#endif // EXPANDERBUTTON2_HPP
