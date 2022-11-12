#ifndef ACTION_H
#define ACTION_H

#include "root_win.h"
#include <QWidget>
#include "widget.h"

namespace Ui {
class action;
}

class action : public QWidget
{
    Q_OBJECT

public:
    explicit action(QWidget *parent = nullptr);
    ~action();


private slots:
    void on_pushButton_2_clicked();

private:
    Ui::action *ui;
};

#endif // ACTION_H
