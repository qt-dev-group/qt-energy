#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMetaObject>
#include <QDebug>
#include <QMetaMethod>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QMetaMethod  qm = this->metaObject()->method(2);
    qDebug()<<qm.name();

}

void MainWindow::test()
{
    qDebug()<<"this is a test";
}
MainWindow::~MainWindow()
{
    delete ui;
}

