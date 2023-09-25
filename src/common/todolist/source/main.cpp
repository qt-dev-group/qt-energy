#include "mainwindow.h"
#include "todolistmdlg.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow w;
    TodolistMdlg w;
    w.show();
    return a.exec();
}
