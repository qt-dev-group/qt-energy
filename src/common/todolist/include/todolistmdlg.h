#ifndef TODOLISTMDLG_H
#define TODOLISTMDLG_H

#include <QWidget>
#include <QTreeWidgetItem>
#include <qicon.h>

namespace Ui {
class TodolistMdlg;
}

class TodolistMdlg : public QWidget
{
    Q_OBJECT

public:
    explicit TodolistMdlg(QWidget *parent = nullptr);
    ~TodolistMdlg();

private slots:
    void on_m_currentToDoListTree_itemPressed(QTreeWidgetItem *item, int column);

    void on_m_currentToDoListTree_itemDoubleClicked(QTreeWidgetItem *item, int column);

    void saveItem(QTreeWidgetItem *item, int column);

private:
    Ui::TodolistMdlg *ui;

    QIcon m_iconAdd;
    QIcon m_iconDelete;

private:
    void initIcons();
    void addOneItem();
};

#endif // TODOLISTMDLG_H
