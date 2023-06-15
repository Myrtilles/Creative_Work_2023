#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    db = QSqlDatabase::addDatabase("QSQLITE", "fst");
    db = QSqlDatabase::database("fst");
    db.open();
    db.setDatabaseName("./PupilsDB.db");
    if(db.open())
    {
        ui->statusbar->showMessage("Успешное подключение к базе данных: " + db.databaseName());
    }
    else
    {
        ui->statusbar->showMessage("При подключении к базе данных произошла ошибка: " + db.lastError().databaseText());
    }

    query = new QSqlQuery(db);
    query->exec("CREATE TABLE Учащиеся( primary key Код TEXT, ФИО TEXT, Дата_рождения TEXT, Класс TEXT, Номер_телефона INT);");

    model = new QSqlTableModel(this, db);
    model->setTable("Учащиеся");
    model->select();


    ui->tableView->setModel(model);
    ui->tableView->setSortingEnabled(true);

    secwin = new SecondWindow;
    connect(secwin, &SecondWindow::firstWindow, this, &MainWindow::show);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_add_clicked()
{
    model->insertRow(model->rowCount());
}

void MainWindow::on_pushButton_delete_clicked()
{
    model->removeRow(row);
}

void MainWindow::on_tableView_clicked(const QModelIndex &index)
{
    row = index.row();
}

void MainWindow::on_commandLinkButton_clicked()
{
    secwin->show();
}

void MainWindow::on_pushButton_clear_clicked()
{
   int TotalRow = model->rowCount();
   for (int i = 0; i < TotalRow; ++i)
   {
       model->removeRow(i);
   }
}

