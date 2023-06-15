#include "tempertest.h"
#include "ui_tempertest.h"

tempertest::tempertest(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::tempertest)
{
    ui->setupUi(this);

}

tempertest::~tempertest()
{
    delete ui;
}

void tempertest::on_lineEdit_editingFinished()
{

}
