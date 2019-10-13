#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "stivastatica.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete arr;
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString nr = ui->inputText->text();
    arr->push = nr.toInt();
}
