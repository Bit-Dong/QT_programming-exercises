#include "widget.h"
#include<QPushButton>
#include"mypushbutton.h"
#include<QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent)
{
    //创建一个按键
    QPushButton *btn1=new QPushButton;
    btn1->show();
    btn1->setParent(this);  //让btn1对象依赖在Widget窗口中
    btn1->setText("第一个按键");  //显示文本
    btn1->move(200,200);   //移动btn1按钮
    //功能： 点击“第一个按键” 实现关闭窗口
    //参数一：信号发送者   参数二：发送的信号（函数的地址）   参数三：信号的接受者  参数四：处理的槽函数
    connect(btn1,&QPushButton::clicked,this,&Widget::close);


    //创建第二个按钮 按照控件的大小创建窗口
    QPushButton *btn2=new QPushButton("第二个按键",this);    //有参构造
    btn2->move(100,100);   //移动btn2按键
    btn2->resize(100,50);    //重新制定btn2大小
    //功能： 点击“第二个按键” 实现关闭窗口
    //参数一：信号发送者   参数二：发送的信号（函数的地址）   参数三：信号的接受者  参数四：处理的槽函数
    connect(btn2,&QPushButton::clicked,this,&Widget::close);

    resize(600,400);    //重置窗口大小
    setFixedSize(600,400);   //设置固定窗口大小
    setWindowTitle("第一个窗口");

    //创建一个自己的按键对象
    MyPushButton *myBtn=new MyPushButton;
    myBtn->setText("我自己的按钮");
    myBtn->move(200,0);
    myBtn->setParent(this);       //设置到对象数中
    //功能： 点击“我自己的按钮” 实现关闭窗口
    //参数一：信号发送者   参数二：发送的信号（函数的地址）   参数三：信号的接受者  参数四：处理的槽函数
   // connect(myBtn,&MyPushButton::clicked,this,&Widget::close);  //与下一行等同
    connect(myBtn,&QPushButton::clicked,this,&QWidget::close);
}

Widget::~Widget()
{
    qDebug()<<"Widget的析构调用";
}
