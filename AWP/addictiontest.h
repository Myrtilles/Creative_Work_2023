#ifndef ADDICTIONTEST_H
#define ADDICTIONTEST_H

#include <QMainWindow>

namespace Ui {
class addictiontest;
}

class addictiontest : public QMainWindow
{
    Q_OBJECT

public:
    explicit addictiontest(QWidget *parent = nullptr);
    ~addictiontest();

signals:
    void testsWindow();

private:
    Ui::addictiontest *ui;
};

#endif // ADDICTIONTEST_H
