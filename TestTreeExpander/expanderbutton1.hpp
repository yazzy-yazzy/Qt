#ifndef EXPANDERBUTTON1_HPP
#define EXPANDERBUTTON1_HPP

#include <QPushButton>

class QTreeWidget;
class QTreeWidgetItem;

class ExpanderButton1 : public QPushButton
{
    Q_OBJECT
public:
    ExpanderButton1(const QString &text, QTreeWidget *parent, QTreeWidgetItem *item);

private slots:
    void ButtonPressed();

private:
    QTreeWidgetItem *_item;
};

#endif // EXPANDERBUTTON1_HPP
