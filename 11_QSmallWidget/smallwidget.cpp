#include "smallwidget.h"
#include "ui_smallwidget.h"

smallwidget::smallwidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::smallwidget)
{
    ui->setupUi(this);

    //QSpinBox数字改变  QSlider跟着移动
    void(QSpinBox:: *spSignal)(int)=&QSpinBox::valueChanged;   //valueChanged()有重载 需要用函数指针指向函数地址
    connect(ui->spinBox,spSignal,ui->horizontalSlider,&QSlider::setValue);
    //QSlider滑动  QSpinBox数字跟着改变
    connect(ui->horizontalSlider,&QSlider::valueChanged,ui->spinBox,&QSpinBox::setValue);
}

//设置数字
void smallwidget:: setNum(int num)
{
    ui->spinBox->setValue(num);
}
//获取数字
int smallwidget::  getnum()
{
    return ui->spinBox->value();
}

smallwidget::~smallwidget()
{
    delete ui;
}
