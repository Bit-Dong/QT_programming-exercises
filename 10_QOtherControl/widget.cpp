#include "widget.h"
#include "ui_widget.h"
#include<QStackedWidget>  //栈空间
#include<QComboBox>   //下拉框
#include<QLabel>  //标签控件
#include<QMovie>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //栈空间使用

    //2、设置默认定位
    ui->stackedWidget->setCurrentIndex(0);   //setCurrentIndex(0) 找序号为0的索引
    //scrollArea按钮
    connect(ui->btn_scroll_area,&QPushButton::clicked,[=](){
        ui->stackedWidget->setCurrentIndex(0);
    });
    //toolBox按钮
    connect(ui->btn_tool_box,&QPushButton::clicked,[=](){
        ui->stackedWidget->setCurrentIndex(2);
    });
    //TabWidget按钮
    connect(ui->btn_tab_widget,&QPushButton::clicked,[=](){
        ui->stackedWidget->setCurrentIndex(1);
    });


    //1、下拉框
    ui->comboBox->addItem("奔驰");    //添加下拉框选项
    ui->comboBox->addItem("宝马");
    ui->comboBox->addItem("保时捷");

    //点击下拉框下的按钮 选中宝马
    connect(ui->btn_baoma,&QPushButton::clicked,[=](){
//        ui->comboBox->setCurrentIndex(1);    //与下一行等同
        ui->comboBox->setCurrentText("宝马");
    });

    //3、利用QLabel显示图片
    ui->label->setPixmap(QPixmap(":/Saved Pictures/Mr.cat.jpg"));
       //利用QLabel显示gif动态图片
//    QMovie *movie=new QMovie("")  //里面添加gif动态图路径
//    ui->label_2->setMovie(movie);
//    movie->start();     //开始播放动态图
}

Widget::~Widget()
{
    delete ui;
}
