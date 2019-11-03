#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog1.h"
#include <QMessageBox>
#include <QComboBox>
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
    QSqlDatabase db;
        db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("bazadanych.db");

        QString PARTIA,CWICZENIE,SERIE,POWTORZENIA,TECHNIKA;
     //   PARTIA=ui->txt_partia->text();
        CWICZENIE=ui->txt_cwiczenie->text();
        SERIE=ui->txt_serie->text();
        POWTORZENIA=ui->txt_powtorzenia->text();
        TECHNIKA=ui->txt_technika->text();

        db.open();
        QSqlQuery qry;
        qry.prepare("insert into bazadanych (PARTIA,CWICZENIE,SERIE,POWTORZENIA,TECHNIKA) values ('"+PARTIA+"','"+CWICZENIE+"','"+SERIE+"','"+POWTORZENIA+"','"+TECHNIKA+"')");

        if(qry.exec())
        {
            QMessageBox::information(this,tr("Zapisz"),tr("Zapisano"));
            db.close();
        }
        else
            QMessageBox::critical(this,tr("Błąd!!!"),tr("Błąd"));
}
