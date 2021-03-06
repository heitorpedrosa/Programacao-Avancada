#include "incluirdvd.h"
#include "ui_incluirdvd.h"

IncluirDVD::IncluirDVD ( QWidget *parent ) : QDialog ( parent ), ui ( new Ui::IncluirDVD ) {
    ui -> setupUi ( this );
}

IncluirDVD::~IncluirDVD () {
    delete ui;
}

void IncluirDVD::on_buttonBox_accepted () {
    QString nome = ui -> line_nome -> text ();
    QString preco = ui -> line_preco -> text ();
    QString duracao = ui -> line_duracao -> text ();

    ui -> line_nome -> setText ( "" );
    ui -> line_preco -> setText ( "" );
    ui -> line_duracao -> setText ( "" );

    emit signIncluirDVD ( nome, preco, duracao );
}
