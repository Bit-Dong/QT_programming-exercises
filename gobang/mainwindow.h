#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include "item.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void DrawChessBroad();//绘制棋盘
    void DrawItems();//绘制棋子
    QVector<Item> m_items;//记录我们的落子
    bool m_bIsBlackTun;//记录落子颜色
    int CountRoundItems(Item it, QPoint pt);//获取一个方向上的棋子数量
    void mousePressEvent(QMouseEvent *event);//鼠标点击落子
    void paintEvent(QPaintEvent *event);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

