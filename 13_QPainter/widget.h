#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QPaintEvent>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

    //绘图事件
    void paintEvent(QPaintEvent *);
    int posX=0;

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
