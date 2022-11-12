#include "findpwd.h"
#include "ui_findpwd.h"
#include "widget.h"

findpwd::findpwd(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::findpwd)
{
    ui->setupUi(this);

    //设置背景为图片
   QPixmap pixmap = QPixmap(":/picture/pc12.png").scaled(this->size());       //设置背景图片
   QPalette  palette (this->palette());
   palette .setBrush(QPalette::Background, QBrush(pixmap));
   this-> setPalette( palette );
}

findpwd::~findpwd()
{
    delete ui;
}

void findpwd::on_abc_clicked()
{
    this->hide();
}

void findpwd::on_push_clicked()
{
    this->hide();
}
