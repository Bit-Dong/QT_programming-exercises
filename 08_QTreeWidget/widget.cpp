#include "widget.h"
#include "ui_widget.h"
#include<QTreeWidget>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //treeWidget树控件使用

    //设置水平的头控件
    ui->treeWidget->setHeaderLabels(QStringList()<<"英雄"<<"英雄介绍");    //QStringList() 创建匿名对象  将“英雄”“英雄介绍”设置为水平的头控件
    //创建根节点节点
    QTreeWidgetItem *liItem=new QTreeWidgetItem(QStringList()<<"力量");
    QTreeWidgetItem *minItem=new QTreeWidgetItem(QStringList()<<"敏捷");
    QTreeWidgetItem *zhiItem=new QTreeWidgetItem(QStringList()<<"智力");
    //设置顶层节点  将根节点添加到数控件上
    ui->treeWidget->addTopLevelItem(liItem);
    ui->treeWidget->addTopLevelItem(minItem);
    ui->treeWidget->addTopLevelItem(zhiItem);
    //追加子节点
    QStringList big1;     //创建容器，存放数据
    big1<<"刚被猪"<<"前排坦克，能在吸收上海的同时造成可观的范围输出";
    QTreeWidgetItem *l1=new QTreeWidgetItem(big1);   //创建节点，并将容器数据传进去
    liItem->addChild(l1);   //将节点l1 设置为 liItem节点的子节点
}

Widget::~Widget()
{
    delete ui;
}
