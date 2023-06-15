#ifndef STRESSTEST_H
#define STRESSTEST_H

#include <QMainWindow>

namespace Ui {
class stresstest;
}

class stresstest : public QMainWindow
{
    Q_OBJECT

public:
    explicit stresstest(QWidget *parent = nullptr);
    ~stresstest();

signals:
    void testsWindow();

private slots:
    void on_lineEdit_editingFinished();

    void on_lineEdit_returnPressed();

    void on_radioButton_clicked();

private:
    Ui::stresstest *ui;
    int i = 0; // индекс страницы
    int stress; // счетчик ответов
};

#endif // STRESSTEST_H
