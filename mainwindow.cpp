#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog1.h"
#include <QMessageBox>
#include <QtSql>
#include <QSqlError>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QSqlDatabase db;
        db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("C:/Users/Zuza/Documents/Projekt2/bazadanych.db");

        if(!db.open())
        {
//           ui->connectdb->setText("Nie udalo sie otworzyc bazy danych.");
    qDebug()<<"Blad bazy";
        }
        else
        {
  //          ui->connectdb->setText("Połączono z bazą danych");
          }
        QSqlDatabase db2;
            db2 = QSqlDatabase::addDatabase("QSQLITE");
            db2.setDatabaseName("C:/Users/Zuza/Documents/Projekt2/bazadanych1.db");

            if(!db2.open())
            {
    //           ui->connectdb->setText("Nie udalo sie otworzyc bazy danych.");
        qDebug()<<"Blad bazy";
            }
            else
            {
      //          ui->connectdb->setText("Połączono z bazą danych");
              }
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
    qDebug()<<"Start";

        QString PARTIA,CWICZENIE,SERIE,POWTORZENIA,TECHNIKA,TEMPO,OBCIAZENIE;
        PARTIA=ui->txt_partia->currentText();
        CWICZENIE=ui->txt_cwiczenie->text();
        SERIE=ui->txt_serie->text();
        POWTORZENIA=ui->txt_powtorzenia->text();
        TECHNIKA=ui->txt_technika->text();
        TEMPO=ui->txt_tempo->text();
        OBCIAZENIE=ui->txt_obciazenie->text();

         //db.open();
         //if(!db.open())
           //  qDebug()<<"Problem z otwarciem bazy "<< db.lastError().text();
         //else
           //  qDebug()<<"Połączono z bazą";

         QSqlQuery qry;

         qry.prepare("insert into exercise (PARTIA,CWICZENIE,SERIE,POWTORZENIA,TECHNIKA,TEMPO,OBCIAZENIE) values ('"+PARTIA+"','"+CWICZENIE+"','"+SERIE+"','"+POWTORZENIA+"','"+TECHNIKA+"','"+TEMPO+"','"+OBCIAZENIE+"')");


         if(qry.exec())
         {
             QMessageBox::information(this,tr("Zapis"),tr("Zapisano"));
             qDebug()<<qry.executedQuery();
             db.close();
            // db.removeDatabase(QSqlDatabase::defaultConnection);

         }
         else
         {
            QMessageBox::critical(this,tr("Błąd"), qry.lastError().text());
            db.close();
             qDebug()<<qry.executedQuery();
            //db.removeDatabase(QSqlDatabase::defaultConnection);
         }

         if(!db.open())
             qDebug()<<"Baza została zamknięta";
         else
             qDebug()<<"Nie zamknięto bazy";
}
