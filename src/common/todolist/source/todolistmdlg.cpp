#include "todolistmdlg.h"
#include "ui_todolistmdlg.h"
#include <qstatusbar.h>
#include <qmessagebox.h>
#include <qsize.h>

TodolistMdlg::TodolistMdlg(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TodolistMdlg)
{
    ui->setupUi(this);

    initIcons();

    QStatusBar* statusbar = new QStatusBar();
    statusbar->showMessage("aaaa");
    ui->verticalLayout_3->addWidget(statusbar,0);

    QSize iconSizeAdd = m_iconAdd.actualSize(QSize(200,200));
    QSize iconSizeDelete = m_iconDelete.actualSize(QSize(200,200));
    int iconSizeReal = iconSizeAdd.width()>iconSizeDelete.width()?iconSizeAdd.width():iconSizeDelete.width();
    ui->m_currentToDoListTree->setColumnWidth(0,iconSizeReal);
    ui->m_currentToDoListTree->setColumnHidden(1, true);

    ui->m_currentToDoListTree->setColumnWidth(0, 100);
    QTreeWidgetItem* eventItem = new QTreeWidgetItem();
    eventItem->setIcon(0, m_iconAdd);
    eventItem->setText(0, QString("Double Click To Edit"));
    eventItem->setText(1, QString("+"));
    eventItem->setFlags(eventItem->flags() | Qt::ItemIsEditable);

    ui->m_currentToDoListTree->addTopLevelItem(eventItem);
    ui->m_currentToDoListTree->resizeColumnToContents(0);



    connect(ui->m_currentToDoListTree, &QTreeWidget::itemChanged, this, &TodolistMdlg::saveItem);
}

TodolistMdlg::~TodolistMdlg()
{
    delete ui;
}

void TodolistMdlg::initIcons()
{
    m_iconAdd = QIcon(":/new/icon/resource/add.png");
    m_iconDelete = QIcon(":/new/icon/resource/delete.png");
}

void TodolistMdlg::on_m_currentToDoListTree_itemPressed(QTreeWidgetItem *item, int column)
{
    if(!item || column != 0 || item->text(1)!=QString("+"))
        return;

    QTreeWidgetItem* eventItem = new QTreeWidgetItem();
    eventItem->setIcon(0, m_iconAdd);
    eventItem->setText(1, "+");

    eventItem->setFlags(eventItem->flags() | Qt::ItemIsEditable);

    ui->m_currentToDoListTree->addTopLevelItem(eventItem);

    item->setIcon(0, m_iconDelete);
    item->setText(1, QString("-"));
}

void TodolistMdlg::on_m_currentToDoListTree_itemDoubleClicked(QTreeWidgetItem *item, int column)
{
    if(column)
    ui->m_currentToDoListTree->editItem(item);
    ui->m_currentToDoListTree->resizeColumnToContents(1);
}

void TodolistMdlg::saveItem(QTreeWidgetItem *item, int column)
{

}
