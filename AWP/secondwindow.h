#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QDebug>
#include <tests.h>

namespace Ui {
class SecondWindow;
}

class SecondWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SecondWindow(QWidget *parent = nullptr);
    ~SecondWindow();

signals:
    void firstWindow();

private slots:
    void on_pushButton_add2_clicked();

    void on_pushButton_delete2_clicked();

    void on_tableView2_clicked(const QModelIndex &index);

    void on_commandLinkButton_clicked();

    void on_pushButton_clear2_clicked();

    void on_commandLinkButton_2_clicked();

private:
    Ui::SecondWindow *ui;
    QSqlDatabase db2;
    QSqlQuery *query2;
    QSqlTableModel *model2;
    tests *t;

    int row2;
};


#endif // SECONDWINDOW_H
