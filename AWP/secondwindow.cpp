#include "secondwindow.h"
#include "ui_secondwindow.h"

SecondWindow::SecondWindow(QWidget *p) :
    QMainWindow(p),
    ui(new Ui::SecondWindow)
{
    ui->setupUi(this);
    db2 = QSqlDatabase::addDatabase("QSQLITE", "scnd");
    db2 = QSqlDatabase::database("scnd");
    db2.open();
    db2.setDatabaseName("./TestsDB.db");
    if(db2.open())
    {
        ui->statusbar->showMessage("Успешное подключение к базе данных: " + db2.databaseName());
    }
    else
    {
        ui->statusbar->showMessage("При подключении к базе данных произошла ошибка: " + db2.lastError().databaseText());
    }

    query2 = new QSqlQuery(db2);
    query2->exec("CREATE TABLE Результаты_тестирований(Код TEXT, Темперамент TEXT, Тип_мышления TEXT, Вредные_привычки TEXT, Психическое_состояние TEXT);");

    model2 = new QSqlTableModel(this, db2);
    model2->setTable("Результаты_тестирований");
    model2->select();



    ui->tableView2->setModel(model2);
    ui->tableView2->setSortingEnabled(true);

    t = new tests;
    connect(t, &tests::secondWindow, this, &SecondWindow::show);
}

SecondWindow::~SecondWindow()
{
    delete ui;
}

void SecondWindow::on_pushButton_add2_clicked()
{
    model2->insertRow(model2->rowCount());
}

void SecondWindow::on_tableView2_clicked(const QModelIndex &index)
{
    row2 = index.row();
}

void SecondWindow::on_pushButton_delete2_clicked()
{
     model2->removeRow(row2);
}


void SecondWindow::on_commandLinkButton_clicked()
{
    this->close();
}

void SecondWindow::on_pushButton_clear2_clicked()
{
   int TotalRow = model2->rowCount();
   for (int i = 0; i < TotalRow; ++i)
   {
       model2->removeRow(i);
   }
}

void SecondWindow::on_commandLinkButton_2_clicked()
{
    t->show();
}
