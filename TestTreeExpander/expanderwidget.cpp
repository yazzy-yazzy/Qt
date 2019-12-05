#include "expanderwidget.hpp"

#include <QVBoxLayout>

#include "expanderbutton1.hpp"
#include "expanderbutton2.hpp"

ExpanderWidget::ExpanderWidget(QWidget *parent) : QTreeWidget(parent)
{
    setHeaderHidden(true);
    setRootIsDecorated(false);
    setIndentation(0);

    {
        QTreeWidgetItem *item = new QTreeWidgetItem();
        addTopLevelItem(item);
        setItemWidget(item, 0, new ExpanderButton2("Category 1", this, item));

        QFrame *frame = new QFrame(this);
        QBoxLayout *layout = new QVBoxLayout(frame);
        layout->addWidget(new QPushButton("Button1"));
        layout->addWidget(new QPushButton("Button2"));

        QTreeWidgetItem *container = new QTreeWidgetItem();
        container->setDisabled(true);
        item->addChild(container);

        setItemWidget(container, 0, frame);
    }
    {
        QTreeWidgetItem *item = new QTreeWidgetItem();
        addTopLevelItem(item);
        setItemWidget(item, 0, new ExpanderButton2("Category 2", this, item));

        QFrame *frame = new QFrame(this);
        QBoxLayout *layout = new QVBoxLayout(frame);
        layout->addWidget(new QPushButton("Button1"));
        layout->addWidget(new QPushButton("Button2"));

        QTreeWidgetItem *container = new QTreeWidgetItem();
        container->setDisabled(true);
        item->addChild(container);

        setItemWidget(container, 0, frame);
    }
}
