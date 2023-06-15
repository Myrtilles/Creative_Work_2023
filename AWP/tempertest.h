#ifndef TEMPERTEST_H
#define TEMPERTEST_H

#include <QMainWindow>

namespace Ui {
class tempertest;
}

class tempertest : public QMainWindow
{
    Q_OBJECT

public:
    explicit tempertest(QWidget *parent = nullptr);
    ~tempertest();

signals:
    void testsWindow();

private slots:
    void on_lineEdit_editingFinished();

private:
    Ui::tempertest *ui;
};

#endif // TEMPERTEST_H
