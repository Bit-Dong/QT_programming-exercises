#include "newwindow.h"
#include "ui_newwindow.h"
#include "widget.h"
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QDebug>
#include <QVector>
#include <QList>
#include <QMessageBox>
#include "user.h"

newWindow::newWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::newWindow)
{
    ui->setupUi(this);

        //设置背景为图片
       QPixmap pixmap = QPixmap(":/picture/pc7.png").scaled(this->size());       //设置背景图片
       QPalette  palette (this->palette());
       palette .setBrush(QPalette::Background, QBrush(pixmap));
       this-> setPalette( palette );


        connect(ui->returnBtn,&QPushButton::clicked,[=](){
            qDebug()<<"跳转至登录界面";
            this->hide(); //关闭注册界面窗口
        });

        connect(ui->regBtn,&QPushButton::clicked,[=](){

            if(ui->userEdit->text()=="")//名字判断
                {
                    //弹窗(是否指定窗口，标题，内容)
                    QMessageBox::information(NULL,"错误","用户名为空");
                }
                else if(ui->pwdEdit->text()=="")//密码判断
                {
                    QMessageBox::information(NULL,"错误","密码为空");
                }
                else if(ui->pwdEdit->text().length()<6)//密码长度判断
                {
                    QMessageBox::information(NULL,"错误","密码长度有误");
                }
                else if(ui->nextpwdEdit->text()=="")
                {
                    QMessageBox::information(NULL,"错误","重新输入密码为空");
                }
                else if(ui->nextpwdEdit->text().length()<6)//重新输入密码长度判断
                {
                    QMessageBox::information(NULL,"错误","重新输入密码长度有误");
                }
                else if(ui->numberEdit->text()=="")
                {
                    QMessageBox::information(NULL,"错误","密码为空");
                }
                else if(ui->numberEdit->text().length()<11)//判断电话号码长度
                {
                    QMessageBox::information(NULL,"错误","电话号码长度有误");
                }
                else if(ui->nextpwdEdit->text()!=ui->pwdEdit->text())
                {
                    QMessageBox::information(NULL,"错误","密码和重新输入密码不一致");
                }
                else
                {
                    int i=0;//判断次数
                    for(i=0;i<User::userlist.size();i++)
                    {
                        if(ui->userEdit->text()==User::userlist.at(i)->GetUserName())//名字是否已被注册判断
                        {
                            QMessageBox::information(NULL,"错误","名字已被注册");
                            break;
                        }
                        else if(ui->numberEdit->text()==User::userlist.at(i)->GetUserNumber())//电话号码是否已被注册判断
                        {
                            QMessageBox::information(NULL,"错误","电话号码已被注册");
                            break;
                        }
                    }
                    if(i>=User::userlist.size())
                    {
                        User *newuser = new User(ui->userEdit->text(),ui->pwdEdit->text(),ui->numberEdit->text());
                        User::userlist.push_back(newuser);
                        QMessageBox::information(NULL,"成功","注册成功");
                        this->hide();  //关闭注册界面窗口

                    }
                }

        });

}

newWindow::~newWindow()
{
    delete ui;
}


void Widget::regSlot(QString name,QString pwd,QString number)
{
    User *newuser = new User(name,pwd,number);
    User::userlist.push_back(newuser);
}


