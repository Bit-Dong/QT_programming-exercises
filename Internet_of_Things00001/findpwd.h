#ifndef FINDPWD_H
#define FINDPWD_H

#include <QWidget>

namespace Ui {
class findpwd;
}

class findpwd : public QWidget
{
    Q_OBJECT

public:
    explicit findpwd(QWidget *parent = nullptr);
    ~findpwd();

private slots:
    void on_toolButton_clicked();

    void on_abc_clicked();

    void on_push_clicked();

private:
    Ui::findpwd *ui;
};

#endif // FINDPWD_H
