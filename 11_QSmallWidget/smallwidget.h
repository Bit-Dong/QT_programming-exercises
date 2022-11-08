#ifndef SMALLWIDGET_H
#define SMALLWIDGET_H

#include <QWidget>

namespace Ui {
class smallwidget;
}

class smallwidget : public QWidget
{
    Q_OBJECT

public:
    explicit smallwidget(QWidget *parent = nullptr);
    ~smallwidget();

    //设置数字
    void setNum(int num);
    //获取数字
    int getnum();

private:
    Ui::smallwidget *ui;
};

#endif // SMALLWIDGET_H
