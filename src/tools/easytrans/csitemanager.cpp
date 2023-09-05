#include "csitemanager.h"
#include "ui_csitemanager.h"
#include <QFile>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QDebug>
#include <QByteArray>
CSiteManager::CSiteManager(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CSiteManager)
{
    ui->setupUi(this);

    m_pSiteListViewModel = new QStandardItemModel(this);

    updateSiteInfo();
}

CSiteManager::~CSiteManager()
{
    delete ui;
}

void CSiteManager::updateSiteInfo()
{
    //read from json file and update
    QString path = QCoreApplication::applicationDirPath();
    path.append("\\site.json");
    QFile file(path);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug()<<"cannot open file";
        return;
    }
    QByteArray jsonData = file.readAll();
    file.close();

    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData);
    if(!jsonDoc.isObject())
    {
        qDebug()<<"wrong json format";
        return;
    }

    QJsonObject jsonObj = jsonDoc.object();
    if(!jsonObj.contains("ftp-sites"))
    {
        qDebug()<<"json file lack of ftp-sites info";
        return;
    }

    QJsonArray ftpSiteArray = jsonObj["ftp-sites"].toArray();

    foreach(const QJsonValue &ftpSiteValue, ftpSiteArray)
    {
        QJsonObject ftpSiteObj = ftpSiteValue.toObject();

        QStandardItem *pItem = new QStandardItem(ftpSiteObj["siteName"].toString());
        m_pSiteListViewModel->appendRow(pItem);
    }

    ui->siteListView->setModel(m_pSiteListViewModel);
    ui->siteListView->show();
}


void CSiteManager::on_newSiteBtn_clicked()
{
    //ui->siteListView->
}

