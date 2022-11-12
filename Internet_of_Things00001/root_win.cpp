#include "root_win.h"
#include "ui_root_win.h"
#include <QMessageBox>
#include "action.h"

root_win::root_win(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::root_win)
{
    ui->setupUi(this);

    QPixmap pixmap = QPixmap(":/picture/pc11.png").scaled(this->size());       //设置背景图片
    QPalette  palette (this->palette());
    palette .setBrush(QPalette::Background, QBrush(pixmap));
    this-> setPalette( palette );

    connect(ui->line3,&QPushButton::clicked,[=](){
        root_win::aaaa();
    });

}

root_win::~root_win()
{
    delete ui;
}

void root_win::aaaa()
{
    if(ui->line1->text()!="root")
    {
        QMessageBox::information(NULL,"error","账号输入错误");
    }
    else if (ui->line2->text()!="123456") {
         QMessageBox::information(NULL,"error","密码输入错误");
    }
    else {
        this->hide();
        root_set *rs=new root_set;
        rs->show();
    }
}

void root_win::on_toolButton_3_clicked()
{
    this->hide();
    action *aaa=new action;
    aaa->show();
}
