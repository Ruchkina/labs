#include "MainWindow.h"
#include <iostream>
#include <fstream>
#include <QApplication>
#include <QFileDialog>
#include <QTextStream>

int main(int argc, char *argv[])
{
    int numStruct;

    QApplication a(argc, argv);
    MainWindow w;

    w.show();
    return a.exec();
}
