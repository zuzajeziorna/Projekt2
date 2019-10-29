#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog1.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("bazadanych.db");

    if(!db.open())
        ui->connectdb->setText("Nie udało się połączyć z bazą danych");
    else
        ui->connectdb->setText("Połączono z bazą danych");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_2_clicked()
{
    hide();
    dialog = new Dialog1(this);
    dialog->show();
}

void MainWindow::on_pushButton_clicked()
{

}
