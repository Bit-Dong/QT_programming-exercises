#ifndef ROOT_SET_H
#define ROOT_SET_H

#include <QWidget>

namespace Ui {
class root_set;
}

class root_set : public QWidget
{
    Q_OBJECT

public:
    explicit root_set(QWidget *parent = nullptr);
    ~root_set();

private slots:
    void on_ton1_clicked();

    void on_ton2_clicked();

    void on_ton3_clicked();

    void on_ton4_clicked();

    void on_ton5_clicked();

    void on_ton6_clicked();

    void on_ton7_clicked();

    void on_ton8_clicked();

    void on_ton9_clicked();

    void on_ton10_clicked();

    void on_ton11_clicked();

    void on_ton12_clicked();

    void on_ton13_clicked();

    void on_ton14_clicked();

    void on_ton15_clicked();

    void on_ton16_clicked();

    void on_toolButton_clicked();

    void on_comboBox_currentTextChanged(const QString &arg1);

private:
    Ui::root_set *ui;
};

#endif // ROOT_SET_H
