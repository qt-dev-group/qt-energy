#ifndef CSITEMANAGER_H
#define CSITEMANAGER_H

#include <QDialog>
#include <QString>

#include <QStandardItem>
#include <QStandardItemModel>


namespace Ui {
class CSiteManager;
}

typedef struct{
    QString siteName;
    QString ivp4addr;
    QString port;
    unsigned int protocol;
    unsigned int loginMode;
    QString username;
    QString password;
    QString comment;
} SITECONFIG;




class CSiteManager : public QDialog
{
    Q_OBJECT

public:
    explicit CSiteManager(QWidget *parent = nullptr);
    ~CSiteManager();

private slots:    
    void on_newSiteBtn_clicked();

private:
    Ui::CSiteManager *ui;
    void updateSiteInfo();
    QStandardItemModel *m_pSiteListViewModel;

};

#endif // CSITEMANAGER_H
