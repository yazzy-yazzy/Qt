#include "expanderbutton1.hpp"

#include <QTreeWidget>
#include <QTreeWidgetItem>

ExpanderButton1::ExpanderButton1( const QString &text, QTreeWidget *parent, QTreeWidgetItem *item )
 : QPushButton(text, parent)
 , _item(item)
{
    connect(this, SIGNAL(pressed()), this, SLOT(ButtonPressed()));
}

void ExpanderButton1::ButtonPressed()
{
    _item->setExpanded(!_item->isExpanded());
}
