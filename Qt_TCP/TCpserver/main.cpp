#include "serverwidget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    serverWidget w;
    w.show();
    return a.exec();
}
