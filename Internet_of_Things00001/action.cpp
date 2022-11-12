#include "action.h"
#include "ui_action.h"

action::action(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::action)
{
    ui->setupUi(this);

    QPixmap pixmap = QPixmap(":/picture/pc10.png").scaled(this->size());       //设置背景图片
    QPalette  palette (this->palette());
    palette .setBrush(QPalette::Background, QBrush(pixmap));
    this-> setPalette( palette );

    connect(ui->pushButton,&QPushButton::clicked,[=](){
        this->hide();
        Widget *w=new Widget;
        w->show();
    });
}

action::~action()
{
    delete ui;
}

void action::on_pushButton_2_clicked()
{
    this->hide();
    root_win *ro=new root_win;
    ro->show();
}
