#include "addictiontest.h"
#include "ui_addictiontest.h"

addictiontest::addictiontest(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::addictiontest)
{
    ui->setupUi(this);
}

addictiontest::~addictiontest()
{
    delete ui;
}
