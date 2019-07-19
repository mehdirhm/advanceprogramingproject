#include "mainwindow.h"
#include <QApplication>
#include "./dfa.hpp"
#include<iostream>
#include"scenegraphic.h"

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
