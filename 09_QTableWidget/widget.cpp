
#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //TableWidget控件

    //1、设置列数
    ui->tableWidget->setColumnCount(3);
    //2、设置水平表头
    ui->tableWidget->setHorizontalHeaderLabels(QStringList()<<"姓名"<<"性别"<<"年龄");
    //3、设置行数
    ui->tableWidget->setRowCount(5);

    //4、设置正文
    //ui->tableWidget->setItem(0,0,new QTableWidgetItem("亚瑟"));     //表示在0行0列添加亚瑟
    QStringList nameList;
    nameList<<"亚索"<<"蛮王"<<"盲僧"<<"机器人"<<"ez";
    QList<QString> sexList;          // QList<QString> sexList  等效于 QStringList sexList
    sexList<<"男"<<"男"<<"男"<<"男"<<"女";
    QStringList ageList;
    ageList<<"21"<<"20"<<"19"<<"23"<<"22";
    for(int i=0;i<5;i++)
    {
        int col=0;
        ui->tableWidget->setItem(i,col++,new QTableWidgetItem(nameList[i]));
        ui->tableWidget->setItem(i,col++,new QTableWidgetItem(sexList.at(i)));
        ui->tableWidget->setItem(i,col++,new QTableWidgetItem(ageList[i]));
    }

}

Widget::~Widget()
{
    delete ui;
}
