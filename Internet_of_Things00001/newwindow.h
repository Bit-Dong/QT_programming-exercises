#ifndef NEWWINDOW_H
#define NEWWINDOW_H

#include <QWidget>
#include "user.h"
namespace Ui {
class newWindow;
}

class newWindow : public QWidget
{
    Q_OBJECT

public:
    explicit newWindow(QWidget *parent = nullptr);
    ~newWindow();


private:
    Ui::newWindow *ui;
};

#endif // NEWWINDOW_H
