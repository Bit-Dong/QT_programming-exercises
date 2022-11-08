#include "widget.h"
#include "ui_widget.h"
#include<QPainter>
#include<QTime>
#include<QTimer>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //点击“移动”按钮，移动图片
//    connect(ui->btn1,&QPushButton::clicked,[=](){
//        posX+=20;
//        update();    //如果需要手动调用绘图事件 用update更新
//    });

  //利用定时器 实现图片自己移动
    QTimer *timer=new QTimer(this);
    timer->start(200);    //启动定时器  200ms触发一次
    connect(timer,&QTimer::timeout,[=](){
        posX+=20;
        update();    //如果需要手动调用绘图事件 用update更新
    });
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *)
{
//    //实例化画家对象 this指定的是绘图设备
//    QPainter painter(this);

//    //设置画笔
//    QPen pen(QColor(150,46,28));
//    //设置画笔宽度
//    pen.setWidth(5);
//    //设置画笔风格
//    pen.setStyle(Qt::DashLine);
//    painter.setPen(pen);    //让画家使用这个笔

//    //设置画刷
//    QBrush brush(Qt::cyan);
//    //设置画刷风格
//    brush.setStyle(Qt::Dense7Pattern);
//    painter.setBrush(brush);    //让画家使用画刷

//    //画线
//    painter.drawLine(0,0,100,100);   //(0，0)到(100，100)的直线

//    //画圆 椭圆
//    painter.drawEllipse(QPoint(100,100),50,50);

//    //画矩形
//    painter.drawRect(100,100,50,20);    //在(100,100)处画向右长为50、向下宽为20的矩形

//    //画文字
//    painter.drawText(QRect(10,200,150,50),"好好学习，天天向上");


    /////////////////////高级设置/////////////////////////////


//    QPainter painter(this);
//    painter.drawEllipse(QPoint(100,50),50,50);
//    //设置 抗锯齿能力  效率较低
//    painter.setRenderHint(QPainter::Antialiasing);
//    painter.drawEllipse(QPoint(200,50),50,50);

//    //画矩形
//    painter.drawRect(QRect(20,20,50,50));
//    painter.translate(100,50);     //移动画家  向右移100个单位、向下平移50个单位
//    painter.save();    //保存画家状态  即保存画家现在这个点位的位置
//    painter.drawRect(QRect(20,70,50,50));
//    painter.translate(100,0);     //移动画家  向右平移100个单位
//    painter.restore();  //还原画家保存状态   即返回(移动)到画家上次保存的位置
//    painter.drawRect(QRect(20,120,50,50));


    //////////////////////  利用画家 画资源图片 /////////////////////
      QPainter painter(this);

      //如果超出屏幕 从0开始
      if(posX > this->width())
      {
          posX=0;
      }


      painter.drawPixmap(posX,0,QPixmap(":/new/prefix1/Saved Pictures/Mr.cat.jpg"));

}
