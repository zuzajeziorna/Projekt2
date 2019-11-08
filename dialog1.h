#ifndef DIALOG1_H
#define DIALOG1_H

#include <QDialog>
#include <QMainWindow>
#include <QSqlDatabase>
#include <QtDebug>
#include <QSqlQuery>

namespace Ui {
class Dialog1;
}

class Dialog1 : public QDialog
{
    Q_OBJECT

public:
    QSqlDatabase db;
    explicit Dialog1(QWidget *parent = nullptr);
    ~Dialog1();

private slots:
    void on_AddWorkout_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Dialog1 *ui;
    QMainWindow *mainwindow;
};

#endif // DIALOG1_H
