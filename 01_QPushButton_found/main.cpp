#include "widget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);    //a应用程序对象，在QT中，应用程序对象有且仅有一个
    Widget w;  //窗口对象，Widget父类 ->QWidget
    w.show();   //窗口对象 默认不会显示 必须要调用show方法显示窗口

    return a.exec();  //让应用程序对象进入消息循环
}
