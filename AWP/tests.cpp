#include "tests.h"
#include "ui_tests.h"

tests::tests(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::tests)
{
    ui->setupUi(this);

    tmprt = new tempertest;
    adctnt = new addictiontest;
    strst = new stresstest;

    connect(tmprt, &tempertest::testsWindow, this, &tests::show);
    connect(adctnt, &addictiontest::testsWindow, this, &tests::show);
    connect(strst, &stresstest::testsWindow, this, &tests::show);
}

tests::~tests()
{
    delete ui;
}

void tests::on_tempertestButton_clicked()
{
    tmprt->show();
    this->close();
}

void tests::on_commandLinkButton_2_clicked()
{
    adctnt->show();
    this->close();
}

void tests::on_commandLinkButton_3_clicked()
{
    strst->show();
    this->close();
}
