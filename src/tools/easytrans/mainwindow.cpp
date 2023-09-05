#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_pSiteManager = NULL;

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_siteManagerBtn_clicked()
{
    if(!m_pSiteManager)
        m_pSiteManager = new CSiteManager(this);

    m_pSiteManager->show();
}

