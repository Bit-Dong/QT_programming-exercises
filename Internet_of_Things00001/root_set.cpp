#include "root_set.h"
#include "ui_root_set.h"
#include <QDebug>
#include "action.h"
#include "lineseries.h"
#include <QString>
#include "run_contorl.h"

root_set::root_set(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::root_set)
{
    ui->setupUi(this);

    QStringList strList;
    strList<<"A1"<<"A2"<<"A3";
    ui->comboBox->addItems(strList);
    //ui->comboBox->setCurrentIndex(2);  //默认显示索引2  A3
}

root_set::~root_set()
{
    delete ui;
}

void root_set::on_ton2_clicked()
{
    qDebug()<<"点击了扫描";
}

void root_set::on_ton3_clicked()
{
    qDebug()<<"点击了断开";
}

void root_set::on_ton4_clicked()
{
    qDebug()<<"点击了发送";
}

void root_set::on_ton5_clicked()
{
    qDebug()<<"点击了获取";
}

void root_set::on_ton6_clicked()
{
    qDebug()<<"点击了清空";
}

void root_set::on_ton7_clicked()
{
    qDebug()<<"点击了设定";
}

void root_set::on_ton8_clicked()
{
    qDebug()<<"点击了开控制";
    this->hide();
    run_contorl *run=new run_contorl;
    run->show();
}

void root_set::on_ton9_clicked()
{
    qDebug()<<"点击了关控制";
}

void root_set::on_ton10_clicked()
{
    qDebug()<<"点击了图表";
    lineseries *line=new lineseries;
    line->show();
}

void root_set::on_ton11_clicked()
{
    qDebug()<<"点击了时间";
}

void root_set::on_ton12_clicked()
{
    qDebug()<<"点击了转速";
}

void root_set::on_ton13_clicked()
{
    qDebug()<<"点击了电压";
}

void root_set::on_ton14_clicked()
{
    qDebug()<<"点击了电流";
}

void root_set::on_ton15_clicked()
{
    qDebug()<<"点击了所有";
}

void root_set::on_ton16_clicked()
{
    qDebug()<<"点击了查询";
}

void root_set::on_toolButton_clicked()
{
    this->hide();
    action * ac=new action;
    ac->show();
}

void root_set::on_ton1_clicked()
{
    qDebug()<<"点击了蓝牙";
}

void root_set::on_comboBox_currentTextChanged(const QString &arg1)
{
    QString str=ui->comboBox->currentText();
    qDebug()<<"当前选择的是 "<<str;
}
