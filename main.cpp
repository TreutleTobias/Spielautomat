#include "mainwindow.h"
#include <spieler.h>
#include <QApplication>
#include <QPushButton>
#include "spieler.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;


    w.show();
    return a.exec();
}
