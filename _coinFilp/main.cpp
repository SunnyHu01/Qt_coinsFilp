#include "mymainwindow.h"
#include "firstwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

//    MyMainWindow w;
//    w.show();

    firstWindow fir;
    fir.show();

    return a.exec();
}
