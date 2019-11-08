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
    //mainwindow = new QMainWindow(this);
//    mainwindow->show();
   ((QMainWindow *) this->parent())->show();
}

QString makeQueryText(QComboBox* combo){
    QString czesc=combo->currentText();
    QString queryText="SELECT * FROM exercise WHERE PARTIA LIKE '"+czesc+"' ORDER BY RANDOM() LIMIT 2;";
    return queryText;
}

void Dialog1::on_pushButton_clicked()
{
    qDebug()<<"Start";
         QSqlQueryModel* modal = new QSqlQueryModel();
         QSqlQuery *qry = new QSqlQuery(db);
         //int idx=ui->comboBox1->currentIndex();
         QString czesc=ui->comboBox1->currentText();
         QString queryText="SELECT * FROM exercise WHERE PARTIA LIKE '"+czesc+"' ORDER BY RANDOM() LIMIT 2;";
         qDebug()<<queryText;
         qry->prepare(queryText);
        // qry->prepare(makeQueryText(ui->comboBox2));
         qry->exec();
         modal->setQuery(*qry);
         ui->Tabela->setModel(modal);


}

void Dialog1::on_pushButton_2_clicked()
{
    //qDebug()<<"Start";

     //    QSqlQueryModel* modal = new QSqlQueryModel();
       //  QSqlQuery *qry = new QSqlQuery(db2);
         //qry->prepare("SELECT * FROM exercise WHERE PARTIA LIKE 'nogi' ORDER BY RANDOM() LIMIT 2;");
        // qry->exec();
         //modal->setQuery(*qry);
         //ui->Tabela->setModel(modal);
}
