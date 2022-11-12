#include "saoma.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    saoma w;
    w.show();

    return a.exec();
}
