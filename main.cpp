#include "mainwindows.h"
#include <QApplication>
#include "udpcontroller.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    udpcontroller myController;
    MainWindows w;
    w.connect_socket(myController);


    w.show();

    return a.exec();
}
