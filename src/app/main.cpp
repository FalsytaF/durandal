#include "durandal.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Durandal w;
    w.show();

    return a.exec();
}
