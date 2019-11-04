#include "dialog1.h"
#include "ui_dialog1.h"
#include <QMessageBox>
#include <QtSql>
#include <QSqlError>
Dialog1::Dialog1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog1)
{
    ui->setupUi(this);

    QSqlDatabase db;
        db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("C:/Users/Zuza/Documents/Projekt2/bazadanych.db");

        if(!db.open())
        {
           ui->connectdb->setText("Nie udalo sie otworzyc bazy danych.");
          }
        else
        {
            ui->connectdb->setText("Połączono z bazą");
          }
}

Dialog1::~Dialog1()
{
    delete ui;
}

void Dialog1::on_AddWorkout_clicked()
{
    hide();
    mainwindow = new QMainWindow(this);
    mainwindow->show();
}

void Dialog1::on_pushButton_clicked()
{
    qDebug()<<"Start";

         QSqlQueryModel* modal = new QSqlQueryModel();
         QSqlQuery *qry = new QSqlQuery(db);
         qry->prepare("Select * FROM exercise");
         qry->exec();
         modal->setQuery(*qry);
         ui->TabelaX->setModel(modal);
}
