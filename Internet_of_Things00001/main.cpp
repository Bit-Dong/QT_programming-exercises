#include "widget.h"
#include "action.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    action abc;
    abc.show();

    return a.exec();
}
