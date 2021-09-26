#include "incluircd.h"
#include "ui_incluircd.h"

IncluirCD::IncluirCD(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::IncluirCD)
{
    ui->setupUi(this);
}

IncluirCD::~IncluirCD()
{
    delete ui;
}

void IncluirCD::on_buttonBox_accepted()
{
    QString nome = ui -> line_nome -> text ();
    QString preco = ui -> line_preco -> text ();
    QString numfaixas = ui -> line_numfaixas -> text ();

    ui -> line_nome -> clear ();
    ui -> line_preco -> clear ();
    ui -> line_numfaixas -> clear ();

    emit signIncluirCD ( nome, preco, numfaixas );
}
