#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "stivastatica.h"

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_popButton_clicked();

    void on_lineEdit_returnPressed();

private:
    Array_Stack stiva;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
