#include "user.h"
#include <QString>
#include <QDebug>

User::User()
{

}


QList<User *> User::userlist;
User::User(QString userName,QString userPwd,QString userNumber)
{
    this->userName =  userName;
    this->userPwd = userPwd;
    this->userNumber = userNumber;
    this->userState =0;//0为不在线
}

User::User(QString userName, QString userPwd, QString userNumber, int userState)
{
    this->userName =  userName;
    this->userPwd = userPwd;
    this->userNumber = userNumber;
    this->userState =userState;//1为在线
}
//用户名
QString User::GetUserName()
{
    return userName;
}

void User::SetUserName(QString userName)
{
    this->userName =  userName;
}
//密码
QString User::GetUserPwd()
{
    return userPwd;
}

void User::SetUserPwd(QString userPwd)
{
    this->userPwd =  userPwd;
}
//手机号
QString User::GetUserNumber()
{
    return userNumber;
}

void User::SetUserNumber(QString userNumber)
{
    this->userNumber =  userNumber;
}
//用户状态
int User::GetUserState()
{
    return userState;
}

void User::SetUserState(int userState)
{
    this->userState =  userState;
}

//void User::addUser()
//{
//    User *newuser1 = new User("admin","123456","13245657467");
//    User *newuser2 = new User("lili","123456","19862948736");
//    userlist.push_back(newuser1);
//    userlist.push_back(newuser2);
//}

void User::print()
{
    for (int i=0;i<userlist.size();i++) {
        qDebug()<<userlist.at(i);
    }
//    qDebug()<<"userName";
//    qDebug()<<"userPwd";
//    qDebug()<<"userNumber";
}
