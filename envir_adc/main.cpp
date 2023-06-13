/*#include "widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();
    return a.exec();
}*/
#include "widget.h"
#include "widget1.h"
#include "widget2.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();
    widget1 w1;

    QObject::connect(&w,SIGNAL(showWidget1()),&w1,SLOT(recvWidget()));
    QObject::connect(&w1,SIGNAL(showWidget()),&w,SLOT(recvW1()));

    widget2 w2;

    QObject::connect(&w,SIGNAL(showWidget2()),&w2,SLOT(recvWidget()));
    QObject::connect(&w2,SIGNAL(showWidget()),&w,SLOT(recvW2()));

    return a.exec();
}
