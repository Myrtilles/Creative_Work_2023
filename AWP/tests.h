#ifndef TESTS_H
#define TESTS_H

#include <QMainWindow>
#include <tempertest.h>
#include <addictiontest.h>
#include <stresstest.h>

namespace Ui {
class tests;
}

class tests : public QMainWindow
{
    Q_OBJECT

public:
    explicit tests(QWidget *parent = nullptr);
    ~tests();

signals:
    void secondWindow();

private slots:
    void on_tempertestButton_clicked();

    void on_commandLinkButton_2_clicked();

    void on_commandLinkButton_3_clicked();

private:
    Ui::tests *ui;
    tempertest *tmprt;
    addictiontest *adctnt;
    stresstest *strst;
};

#endif // TESTS_H
