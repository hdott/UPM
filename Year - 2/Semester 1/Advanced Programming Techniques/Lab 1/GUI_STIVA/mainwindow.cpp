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
    if(!stiva.isFull()){
        stiva.push(nr.toInt());
    }

    ui->lineEdit->clear();

    if(stiva.isFull()){
        ui->listWidget->addItem("Lista este Plina!");
    }

    for(int i=stiva.Iterator(); i>=0; --i){
        ui->listWidget->addItem(QString::number(stiva.PeekItem(i)));
    }
}

void MainWindow::on_popButton_clicked()
{
    ui->listWidget->clear();

    if(!stiva.isEmpty()){
        stiva.pop();

        for(int i=stiva.Iterator(); i>=0; --i){
            ui->listWidget->addItem(QString::number(stiva.PeekItem(i)));
        }
    } else{
        ui->listWidget->addItem("Stiva este goala!");
    }
}

void MainWindow::on_lineEdit_returnPressed()
{
    MainWindow::on_pushButton_clicked();
}
