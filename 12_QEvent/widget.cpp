#include "widget.h"
#include "ui_widget.h"
#include<QTimer>
#include<QMouseEvent>
#include<QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //启动定时器
    Id1=startTimer(1000);   //参数1: 间隔(单位：ms)
    Id2=startTimer(2000);

    //定时器第二种方式
    QTimer *timer=new QTimer(this);
    timer->start(500);    //启动定时器
    connect(timer,&QTimer::timeout,[=](){
        static int num=1;
        ui->label_4->setText(QString::number(num++));     //label4每隔0.5秒+1
    });

    //点击暂停按钮 实现停止定时器
    connect(ui->btn1,&QPushButton::clicked,[=](){
        timer->stop();
    });
    //点击继续按钮 实现定时器继续计数
    connect(ui->btn2,&QPushButton::clicked,[=](){
        timer->start(500);
    });

    //给label1安装事件过滤器
    //步骤一 安装事件过滤器
    ui->label->installEventFilter(this);

}

//步骤二 重写eventfilter事件
bool Widget::eventFilter(QObject *obj, QEvent *e)
{
    if(obj==ui->label)
    {
        if(e->type()==QEvent::MouseButtonPress)
        {
            QMouseEvent *ev=static_cast<QMouseEvent *>(e);
            QString str=QString("事件过滤器中：：鼠标按下了  x=%1  Y=%2  globalX=%3  globalY=%4 ").arg(ev->x()).arg(ev->y()).arg(ev->globalX()).arg(ev->globalY());
            qDebug()<<str;

            return true;   //true代表用户自己处理这个事件，不向下分发
        }
    }
    //其他默认处理
    return QWidget::eventFilter(obj,e);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::timerEvent(QTimerEvent *event)
{
    if(event->timerId()==Id1)
    {
        static int num=1;
        ui->label_2->setText(QString::number(num++));    //int型转QString &  用QString::number()
    }

    if(event->timerId()==Id2)
    {
        static int num2=1;
        ui->label_3->setText(QString::number(num2++));
    }

}
