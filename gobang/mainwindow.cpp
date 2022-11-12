#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMouseEvent>
#include <QPainter>
#include <QMessageBox>
//棋盘行和列
#define CHESS_ROWS 18
#define CHESS_COLUMES 18
//棋盘格的宽、高
#define RECT_WIDTH 25
#define RECT_HEIGHT 25

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //比18*25.5稍微大一些
    resize(480,480);
    m_bIsBlackTun = 0;//初始化落子颜色 0 为白色 1为黑色
    m_items.clear();//清空我们的落子
}
void MainWindow::DrawChessBroad(){
    //鼠标光标定位到QPainter，按F1查看帮助文档，找到drawRect函数
    QPainter painter(this);
    QPen pen;//画笔
    pen.setColor(Qt::black);//定义画笔颜色
    pen.setWidth(2);//设置画笔的宽度
    QBrush brush(QColor(Qt::darkYellow));//画刷并设置颜色
    painter.setPen(pen);//添加画笔
    painter.setBrush(brush);//添加画刷
    //因为我们要绘制18*18的棋盘，所以我们使用双重for循环来绘制18*18个棋盘格子
    for(int j = 0;j<CHESS_COLUMES;j++)
    {
        for(int i = 0;i<CHESS_ROWS;i++)
        {
            //我们使用drawRect(int x, int y, int width, int height)来绘制一个矩形（棋盘格子）
            //前两个参数代表矩形的左上顶点，后两个参数代表矩形的宽高
            painter.drawRect((i+0.5)*RECT_WIDTH,(j+0.5)*RECT_HEIGHT,RECT_WIDTH,RECT_HEIGHT);
        }
    }
}

//获取一个方向的棋子数量
int MainWindow::CountRoundItems(Item it, QPoint pt)
{
    Item it1 = it;//通过it1来获取当前棋子
    it1.m_pt += pt;//获取对应方向的棋子
    int counter = 0;
    while (m_items.contains(it1)) {//判断it1是否在m_items中
        counter++;//在这个方向的棋子数
        it1.m_pt += pt;
    }
    return counter;//返回棋子数量
}

void MainWindow::DrawItems(){
    QPainter painter(this);
    QPen pen;
    QBrush brush;
    pen.setColor(Qt::transparent);//设置画笔颜色为透明色
    painter.setPen(pen);
    //循环我们的所有落子，并绘制出来
    for(int i = 0;i<m_items.size();i++)
    {
        Item item = m_items[i];
        //判断是黑方还是白方落子
        if(item.m_bBlack)
        {
            painter.setBrush(Qt::black);
        }else {
            painter.setBrush(Qt::white);
        }
        //获取棋子的位置
        QPoint ptCenter((item.m_pt.x()+0.5)*RECT_WIDTH,(item.m_pt.y()+0.5)*RECT_HEIGHT);
        //绘制棋子，棋子的半径为宽高的一半
        painter.drawEllipse(ptCenter,RECT_WIDTH/2,RECT_HEIGHT/2);
    }
}
void MainWindow::mousePressEvent(QMouseEvent *event)
{
    QPoint pt;//定义一个点
    int chess_x = event->pos().x();//获取鼠标点击的x坐标
    int chess_y = event->pos().y();//获取鼠标点击的y坐标
    pt.setX(chess_x/RECT_WIDTH);//设置棋子x坐标
    pt.setY(chess_y/RECT_HEIGHT);//设置棋子y坐标
    //循环所有棋子判断落子处是否存在棋子
    for(int i = 0;i<m_items.size();i++){
        Item item = m_items[i];
        if(item.m_pt == pt){
            return;
        }
    }
    Item item(pt,m_bIsBlackTun);//设定棋子坐标及颜色
    m_items.append(item);//添加棋子到所有的棋子
    //判定是否赢
    int Left = CountRoundItems(item,QPoint(-1,0));//获取左边棋子的数量
    int Right = CountRoundItems(item,QPoint(+1,0));
    int Up = CountRoundItems(item,QPoint(0,-1));
    int Down = CountRoundItems(item,QPoint(0,+1));
    int LeftUp = CountRoundItems(item,QPoint(-1,-1));
    int LeftDown = CountRoundItems(item,QPoint(-1,+1));
    int RightUp = CountRoundItems(item,QPoint(+1,-1));
    int RightDown = CountRoundItems(item,QPoint(+1,+1));
    //判定四种情况
    if((Left+Right >= 4)|| (Up+Down)>=4 || (LeftUp+RightDown)>=4||(RightUp + LeftDown>=4))
    {
        QString strTip = item.m_bBlack?"黑棋胜出！":"白棋胜出！";//判断当前落子的颜色给出相应的获胜提示
        QMessageBox::information(this,"提示胜利",strTip,QMessageBox::Yes);
        m_items.clear();//清空所有落子
        return;
    }
    m_bIsBlackTun = !m_bIsBlackTun;//切换棋子颜色
}
void MainWindow::paintEvent(QPaintEvent *event)
{
    //绘制棋盘
    DrawChessBroad();
    //绘制棋子
    DrawItems();
    //更新
    update();
}

MainWindow::~MainWindow()
{
    delete ui;
}

