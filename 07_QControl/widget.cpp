#include "widget.h"
#include "ui_widget.h"
#include<QDebug>
#include<QListWidget>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //设置单选按钮 男默认选中
    ui->radioButtonMan->setChecked(true);
    //选中女后 打印信息
    connect(ui->radioButtonWoman,&QRadioButton::clicked,[=](){
        qDebug()<<"当前选中女";
    });

    //设置多选按钮  2是选中 0是未选中
    connect(ui->bossWoman,&QCheckBox::stateChanged,[=](int state){
        qDebug()<<state;
    });


    //利用listWidget写诗
//    QListWidgetItem *item=new QListWidgetItem("锄禾日当午");   //创建ListWidget控件
//    ui->listWidget->addItem(item);    //将一行诗放入到listWidget控件中
//    item->setTextAlignment(Qt::AlignHCenter);   //设置诗句居中

    //QStringList    QList<QString>
    QStringList list;     //创建QStringList容器  存放诗句
    list<<"锄禾日当午"<<"汗滴禾下土"<<"谁知盘中餐"<<"粒粒皆辛苦";
    ui->listWidget->addItems(list);    //将容器放入控件中
}

Widget::~Widget()
{
    delete ui;
}
