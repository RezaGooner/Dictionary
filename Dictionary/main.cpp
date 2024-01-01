#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setFixedHeight(300);
    w.setFixedWidth(900);
    w.show();
    return a.exec();
}
