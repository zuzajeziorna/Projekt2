#ifndef TABELA_H
#define TABELA_H

#include <QDialog>

namespace Ui {
class Tabela;
}

class Tabela : public QDialog
{
    Q_OBJECT

public:
    explicit Tabela(QWidget *parent = nullptr);
    ~Tabela();

private:
    Ui::Tabela *ui;
};

#endif // TABELA_H
