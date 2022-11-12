#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLabel>
#include "newwindow.h"
#include "user.h"
#include <QDebug>
#include <QString>
#include "erwei.h"
#include "action.h"
#include "root_win.h"
#include "findpwd.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();
    void regSlot(QString name,QString pwd,QString number);

private slots:
    void on_btn_zhuce_clicked();

    void on_erweima_clicked();

    void on_toolButton_3_clicked();

    void on_btn_denglu_clicked();

    void on_toolButton_2_clicked();

    void on_find_pwd_clicked();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
