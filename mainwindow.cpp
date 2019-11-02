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
    QSqlDatabase db;
        db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("C:/Users/matiz/Desktop/Roboczy Qt/Plan_lekcji/Baza_planu_zajec.db");

        QString PARTIA,CWICZENIE,SERIE,POWTORZENIA,TECHNIKA;
        PARTIA=ui->txt_partia->text();
        CWICZENIE=ui->txt_cwiczenie->text();
        SERIE=ui->txt_serie->text();
        POWTORZENIA=ui->txt_powtorzenia->text();
        TECHNIKA=ui->txt_technika->text();

        db.open();
        QSqlQuery qry;
        qry.prepare("insert into Dane_osobowe (ID,Imie,Nazwisko) values ('"+ID+"','"+Imie+"','"+Nazwisko+"')");

        if(qry.exec())
        {
            QMessageBox::information(this,tr("Zapisz"),tr("Zapisano"));
            db.close();
        }
        else
            QMessageBox::critical(this,tr("Błąd!!!"),qry.lastError().text());
}
