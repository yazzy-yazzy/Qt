#ifndef SPLITTEREX_HPP
#define SPLITTEREX_HPP

#include <QSplitter>
#include <QSplitterHandle>

class SplitterEx : public QSplitter
{
    Q_OBJECT
public:
    explicit SplitterEx(Qt::Orientation orientation, QWidget *parent = nullptr);
    explicit SplitterEx(QWidget *parent = nullptr);

signals:

public slots:

protected:
    QSplitterHandle *createHandle() override;
};

class SplitterHandleEx : public QSplitterHandle
{
    Q_OBJECT
public:
    SplitterHandleEx(Qt::Orientation orientation, QSplitter *parent = nullptr);

    QSize sizeHint() const override;

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void paintEvent(QPaintEvent *event) override;

private:
    bool isCollapsed() const;

};

#endif // SPLITTEREX_HPP
