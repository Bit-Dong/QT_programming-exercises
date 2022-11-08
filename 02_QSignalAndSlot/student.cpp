#include "student.h"
#include<QDebug>

Student::Student(QObject *parent) : QObject(parent)
{

}

void Student::treat()
{
    qDebug()<<"请老师吃饭";
}

void Student::treat(QString foodName)
{
    //qDebug()<<"请老师吃饭，老师要吃："<<foodName ;  //这行代码输出的是“请老师吃饭，老师要吃："宫保鸡丁"”
                                                //  即 宫保鸡丁 旁边会有引号显示出来
    //若想去掉引号 需要将变量的QString型 转化为 char *型   先转成QByteArray(.toUtf8()) 再转char *(.data())
    qDebug()<<"请老师吃饭，老师要吃："<<foodName.toUtf8().data();   //这样就没有引号了
}
