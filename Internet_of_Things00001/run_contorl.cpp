#include "run_contorl.h"
#include "ui_run_contorl.h"
#include "root_set.h"
#include <QDebug>

run_contorl::run_contorl(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::run_contorl)
{
    ui->setupUi(this);
}

run_contorl::~run_contorl()
{
    delete ui;
}

void run_contorl::on_toolButton_clicked()
{
    this->hide();
    root_set *rr=new root_set;
    rr->show();
}

void run_contorl::on_pushButton_clicked()
{
    qDebug()<<"打开照明灯";
}

void run_contorl::on_pushButton_2_clicked()
{
    qDebug()<<"关闭照明灯";
}

void run_contorl::on_pushButton_3_clicked()
{
    qDebug()<<"打开电机";
}

void run_contorl::on_pushButton_4_clicked()
{
    qDebug()<<"关闭电机";
}

void run_contorl::on_pushButton_5_clicked()
{
    qDebug()<<"转向灯1";
}

void run_contorl::on_pushButton_6_clicked()
{
    qDebug()<<"转向灯2";
}

void run_contorl::on_pushButton_7_clicked()
{
    qDebug()<<"转向灯3";
}

void run_contorl::on_pushButton_8_clicked()
{
    qDebug()<<"转向灯4";
}

void run_contorl::on_pushButton_9_clicked()
{
    qDebug()<<"蜂鸣器1";
}

void run_contorl::on_pushButton_10_clicked()
{
    qDebug()<<"蜂鸣器2";
}

void run_contorl::on_pushButton_11_clicked()
{
    qDebug()<<"蜂鸣器3";
}

void run_contorl::on_pushButton_12_clicked()
{
    qDebug()<<"蜂鸣器4";
}

void run_contorl::on_pushButton_13_clicked()
{
    qDebug()<<"速度1";
}

void run_contorl::on_pushButton_14_clicked()
{
    qDebug()<<"速度2";
}

void run_contorl::on_pushButton_15_clicked()
{
    qDebug()<<"速度3";
}

void run_contorl::on_pushButton_16_clicked()
{
    qDebug()<<"速度4";
}

void run_contorl::on_pushButton_17_clicked()
{
    qDebug()<<"速度5";
}

void run_contorl::on_pushButton_18_clicked()
{
    qDebug()<<"光照保存设置";
}

void run_contorl::on_pushButton_19_clicked()
{
    qDebug()<<"电压保存设置";
}
