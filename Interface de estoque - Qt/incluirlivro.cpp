#include "incluirlivro.h"
#include "ui_incluirlivro.h"

IncluirLivro::IncluirLivro ( QWidget *parent ) : QDialog ( parent ), ui ( new Ui::IncluirLivro ) {
    ui -> setupUi ( this );
}

IncluirLivro::~IncluirLivro () {
    delete ui;
}

void IncluirLivro::on_buttonBox_accepted () {
    QString nome = ui -> line_nome -> text ();
    QString preco = ui -> line_preco -> text ();
    QString autor = ui -> line_autor -> text ();

    ui -> line_nome -> setText ( "" );
    ui -> line_preco -> setText ( "" );
    ui -> line_autor -> setText ( "" );

    emit signIncluirLivro ( nome, preco, autor );
}
