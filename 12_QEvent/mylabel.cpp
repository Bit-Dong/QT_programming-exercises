#include "mylabel.h"
#include<QDebug>
#include<QMouseEvent>
#include<QEvent>

mylabel::mylabel(QWidget *parent) : QLabel(parent)
{
    //设置鼠标追踪状态
  //  setMouseTracking(true);    //默认是false  设置为true后，只要鼠标移动就会输出信息（需要先把下面的if(左键)语句注释，不然会受到左键的限制）
}

//鼠标进入事件
void mylabel::enterEvent(QEvent *event)
{
    qDebug()<<"鼠标进入了";
}

//鼠标离开事件
void mylabel::leaveEvent(QEvent *)
{
    qDebug()<<"鼠标离开了";
}

//鼠标按下事件
void mylabel::mousePressEvent(QMouseEvent *ev)
{
    //当鼠标左键按下 提示信息
    if(ev->button()==Qt::LeftButton)
    {
        QString str=QString("鼠标按下了  x=%1  Y=%2  globalX=%3  globalY=%4 ").arg(ev->x()).arg(ev->y()).arg(ev->globalX()).arg(ev->globalY());
        qDebug()<<str;
    }
}

//鼠标释放事件
void mylabel::mouseReleaseEvent(QMouseEvent *ev)
{
    //当鼠标左键按下 提示信息
    if(ev->button()==Qt::LeftButton)
    {
        QString str=QString("鼠标释放了  x=%1  Y=%2  globalX=%3  globalY=%4 ").arg(ev->x()).arg(ev->y()).arg(ev->globalX()).arg(ev->globalY());
        qDebug()<<str;
    }
}

//鼠标移动事件
void mylabel::mouseMoveEvent(QMouseEvent *ev)
{
    //当鼠标左键和右键(或中键滚轮)同时按下 提示信息
    if(ev->buttons()&Qt::LeftButton)
    {
        QString str=QString("鼠标移动了  x=%1  Y=%2  globalX=%3  globalY=%4 ").arg(ev->x()).arg(ev->y()).arg(ev->globalX()).arg(ev->globalY());
        qDebug()<<str;
    }
}

 bool mylabel::event(QEvent *e)   //这里点的快就拦截不了了
{
    //如果是鼠标按下，在event事件分发中做拦截操作
     if(e->type()==QEvent::MouseButtonPress)
     {
         QMouseEvent *ev=static_cast<QMouseEvent *>(e);
         QString str=QString("Event函数中：：鼠标按下了  x=%1  Y=%2  globalX=%3  globalY=%4 ").arg(ev->x()).arg(ev->y()).arg(ev->globalX()).arg(ev->globalY());
         qDebug()<<str;

         return true;   //true代表用户自己处理这个事件，不向下分发
     }
     //其他事件 交给父类处理 默认处理
     return QLabel::event(e);
}
