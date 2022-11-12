#ifndef USER_H
#define USER_H

#include <QList>
class User
{
public:

    User();
    User(QString userName,QString userPwd,QString userNumber);
        User(QString userName,QString userPwd,QString userNumber,int userState);
        ~User();
        //获取用户名
        QString GetUserName();
        void SetUserName(QString userName);
        //获取密码
        QString GetUserPwd();
        void SetUserPwd(QString userPwd);
        //获取手机号
        QString GetUserNumber();
        void SetUserNumber(QString userNumber);
        //获取用户状态
        int GetUserState();
        void SetUserState(int userState);
        //定义用户链表
        static QList<User *> userlist;
        static void addUser();//初始化链表

        //输出所有用户
        void print();

    private:
        QString userName;
        QString userPwd;
        QString userNumber;
        int userState;//用户状态 0为不在线 1在线

};

#endif // USER_H
