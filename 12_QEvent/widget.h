#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QTimerEvent>
#include<QTime>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();
    void timerEvent(QTimerEvent *event);

    int Id1;
    int Id2;

    //重写eventfilter事件
    bool eventFilter(QObject *obj,QEvent *e);

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
