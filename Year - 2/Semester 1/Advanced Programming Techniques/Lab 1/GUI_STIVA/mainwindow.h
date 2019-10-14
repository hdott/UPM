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

private:
    Array_Stack stiva;
    QStringList lista;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
