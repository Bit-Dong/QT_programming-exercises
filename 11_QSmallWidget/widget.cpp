#include "widget.h"
#include "ui_widget.h"
#include<QDebug>
#include<QPushButton>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //点击获取
    connect(ui->btn_get,&QPushButton::clicked,[=](){
        qDebug()<<ui->widget->getnum();
    });
    //设置数值  这里设置为一半
    connect(ui->btn_set,&QPushButton::clicked,[=](){
        ui->widget->setNum(50);
    });
}

Widget::~Widget()
{
    delete ui;
}
