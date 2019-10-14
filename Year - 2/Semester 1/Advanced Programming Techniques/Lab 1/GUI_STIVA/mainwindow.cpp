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
    stiva.~Array_Stack();
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    ui->listWidget->clear();
    QString nr = ui->lineEdit->text();
    stiva.push(nr.toInt());

    for(int i=stiva.Iterator(); i>=0; --i){
        QString tmp = std::to_string(stiva.PeekItem(i));
        ui->listWidget->addItem(tmp);
    }

}
