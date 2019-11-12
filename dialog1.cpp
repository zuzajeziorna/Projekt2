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


//QString makeText(QComboBox* combo2){
   // QString czesc2=combo2->currentText();
  //  QString queryText="SELECT * FROM exercise WHERE PARTIA LIKE '"+czesc2+"' ORDER BY RANDOM() LIMIT 2;";
  //  return queryText;
QString makeQueryText(QComboBox* combo){
    QString czesc=combo->currentText();
    QString queryText="SELECT * FROM exercise WHERE PARTIA LIKE '"+czesc+"' ORDER BY RANDOM() LIMIT 2;";
    return queryText;
}
void Dialog1::on_pushButton_clicked()
{
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

    qDebug()<<"Start";
    QSqlQueryModel* modal = new QSqlQueryModel();
             QSqlQuery *qry = new QSqlQuery(db);
             qry->prepare("Select * FROM exercise");
             //int idx=ui->comboBox1->currentIndex();
             QString czesc=ui->comboBox1->currentText();
         //  QString czesc2=ui->comboBox2->currentText();
         //  QString czesc=ui->comboBox3->currentText();
             QString queryText="SELECT * FROM exercise WHERE PARTIA LIKE '"+czesc+"' ORDER BY RANDOM() LIMIT 2;";
         //  QString quryText="SELECT * FROM exercise WHERE PARTIA LIKE '"+czesc2+"' ORDER BY RANDOM() LIMIT 2;";
             qDebug()<<queryText;
             qry->prepare(queryText);
             qry->prepare(makeQueryText(ui->comboBox1));
             qry->exec();
             modal->setQuery(*qry);
             ui->Tabela->setModel(modal);

//             QSqlQueryModel* modal2 = new QSqlQueryModel();
//                      QSqlQuery *qry2 = new QSqlQuery(db);
//                      qry->prepare("Select * FROM exercise");
//                      //int idx=ui->comboBox1->currentIndex();
//                     // QString czesc=ui->comboBox1->currentText();
//                      QString czesc2=ui->comboBox2->currentText();
//                       QString queryText1="SELECT * FROM exercise WHERE PARTIA LIKE '"+czesc2+"' ORDER BY RANDOM() LIMIT 2;";
//                       qry2->prepare(queryText);
//                      // qry->prepare(makeQueryText(ui->comboBox2));
//                       qry2->exec();
//                       modal2->setQuery(*qry2);
//                       ui->Tabela->setModel(modal2);
}
QString makeQueryText1(QComboBox* combo){
    QString czesc=combo->currentText();
    QString queryText1="SELECT * FROM zaawansowane WHERE PARTIA LIKE '"+czesc+"' ORDER BY RANDOM() LIMIT 2;";
    return queryText1;
}
void Dialog1::on_pushButton_2_clicked()
{

    QSqlDatabase db2;
        db2 = QSqlDatabase::addDatabase("QSQLITE");
        db2.setDatabaseName("C:/Users/Zuza/Documents/Projekt2/bazadanych1.db");

        if(!db2.open())
        {
           ui->connectdb->setText("Nie udalo sie otworzyc bazy danych.");
          }
        else
        {
            ui->connectdb->setText("Połączono z bazą");
          }


    qDebug()<<"Start";
    QSqlQueryModel* modal = new QSqlQueryModel();
             QSqlQuery *qry = new QSqlQuery(db2);
             qry->prepare("Select * FROM zaawansowane");
             //int idx=ui->comboBox5->currentIndex();
             QString czesc=ui->comboBox4->currentText();
       //    QString czesc2=ui->comboBox5->currentText();
             QString queryText1="SELECT * FROM zaawansowane WHERE PARTIA LIKE '"+czesc+"' ORDER BY RANDOM() LIMIT 2;";
         //  QString quryText="SELECT * FROM exercise WHERE PARTIA LIKE '"+czesc2+"' ORDER BY RANDOM() LIMIT 2;";
             qDebug()<<queryText1;
             qry->prepare(queryText1);
             qry->prepare(makeQueryText1(ui->comboBox4));
             qry->exec();
             modal->setQuery(*qry);
             ui->Tabela->setModel(modal);

}
