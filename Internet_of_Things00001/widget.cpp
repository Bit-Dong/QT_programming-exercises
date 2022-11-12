#include "widget.h"
#include "ui_widget.h"
#include <QPushButton>
#include "root_win.h"
#include "action.h"
#include <QMessageBox>
#include "saoma.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

      //设置背景为图片
     QPixmap pixmap = QPixmap(":/picture/pc3.jpg").scaled(this->size());       //设置背景图片
     QPalette  palette (this->palette());
     palette .setBrush(QPalette::Background, QBrush(pixmap));
     this-> setPalette( palette );

   //输出已存储的用户
     connect(ui->abc,&QPushButton::clicked,[=](){
         for (int i=0;i<User::userlist.size();i++) {
             qDebug()<<User::userlist.at(i)->GetUserName();
             qDebug()<<User::userlist.at(i)->GetUserPwd();
             qDebug()<<User::userlist.at(i)->GetUserNumber();
         }
     });



}

Widget::~Widget()
{
    delete ui;
}



void Widget::on_btn_zhuce_clicked()
{
    newWindow *configWindow = new newWindow;



    configWindow->show();
}


void Widget::on_erweima_clicked()
{
//    erwei *cof=new erwei;
//    cof->show();
    saoma *sao=new saoma;
    sao->show();
}

void Widget::on_toolButton_3_clicked()
{
    this->hide();
    action *aaa=new action;
    aaa->show();
}

void Widget::on_btn_denglu_clicked()
{
    int flag=0;
    for (int i=0;i<User::userlist.size();i++) {
        if(ui->yonghuming->text()==User::userlist.at(i)->GetUserName()){
            flag=1;
            if(ui->mima->text()==User::userlist.at(i)->GetUserPwd()){
                QMessageBox::information(NULL,"success","登录成功");
            }
            else {
                QMessageBox::information(NULL,"error","密码错误");
            }
        }
    }
    if(flag==0)  QMessageBox::information(NULL,"error","用户不存在");
}


void Widget::on_find_pwd_clicked()
{
    findpwd *fd=new findpwd;
    fd->show();
}
