#include "stresstest.h"
#include "ui_stresstest.h"

stresstest::stresstest(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::stresstest)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(i);
}

stresstest::~stresstest()
{
    delete ui;
}


void stresstest::on_lineEdit_returnPressed()
{
    ui->stackedWidget->setCurrentIndex(i+1);
}


