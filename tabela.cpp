#include "tabela.h"
#include "ui_tabela.h"

Tabela::Tabela(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Tabela)
{
    ui->setupUi(this);
}

Tabela::~Tabela()
{
    delete ui;
}
