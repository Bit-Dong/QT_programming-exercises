#ifndef ROOT_WIN_H
#define ROOT_WIN_H

#include <QWidget>
#include "root_set.h"

namespace Ui {
class root_win;
}

class root_win : public QWidget
{
    Q_OBJECT

public:
    explicit root_win(QWidget *parent = nullptr);
    ~root_win();
    void aaaa();

private slots:
    void on_toolButton_3_clicked();

private:
    Ui::root_win *ui;
};

#endif // ROOT_WIN_H
