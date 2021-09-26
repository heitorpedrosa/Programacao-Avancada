#include "mainloja.h"
#include "ui_mainloja.h"
#include <QTableWidget>
#include <QFileDialog>
#include <QMessageBox>
#include <cmath>

MainLoja::MainLoja(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainLoja)
    , X()
    , inclLivro ( nullptr )
    , inclCD ( nullptr )
    , inclDVD ( nullptr )
    , total_itens ( nullptr )
{

    ui->setupUi(this);

    inclLivro = new IncluirLivro ( this );
    inclCD = new IncluirCD ( this );
    inclDVD = new IncluirDVD ( this );

/*******************************************STATUSBAR******************************************/

    ui -> statusbar -> insertWidget( 0, new QLabel ( "Total de itens: " ) );

    total_itens = new QLabel ( this );
    total_itens -> setNum ( 0 );
    ui -> statusbar -> insertWidget ( 1, total_itens );

/**********************************************************************************************/


/*******************************************CONNECTS*******************************************/

    connect ( inclLivro, &IncluirLivro::signIncluirLivro, this, &MainLoja::slotIncluirLivro );
    connect ( inclCD, &IncluirCD::signIncluirCD , this, &MainLoja::slotIncluirCD );
    connect ( inclDVD, &IncluirDVD::signIncluirDVD , this, &MainLoja::slotIncluirDVD );

/**********************************************************************************************/


/*******************************************ESTILO*********************************************/

    //tabela Livro
    ui -> label_livro -> setStyleSheet( "background: lightgray" );
    ui -> label_livro -> setAlignment ( Qt::AlignCenter );
    ui -> tabela_livro -> setStyleSheet ( "QHeaderView::section { background-color:lightgray }" );
    ui -> tabela_livro -> horizontalHeader () -> setSectionResizeMode ( 1, QHeaderView::ResizeToContents );
    ui -> tabela_livro -> horizontalHeader () -> setSectionResizeMode ( 2, QHeaderView::ResizeToContents );
    ui -> tabela_livro -> horizontalHeader () -> setSectionResizeMode ( 0, QHeaderView::Stretch );
    ui -> tabela_livro -> setHorizontalHeaderLabels ( QStringList () << "NOME" << "PRECO" << "AUTOR" );

    //tabela CD
    ui -> label_cd -> setStyleSheet( "background: lightgray" );
    ui -> label_cd -> setAlignment ( Qt::AlignCenter );
    ui -> tabela_cd -> setStyleSheet ( "QHeaderView::section { background-color:lightgray }" );
    ui -> tabela_cd -> horizontalHeader () -> setSectionResizeMode ( 1, QHeaderView::ResizeToContents );
    ui -> tabela_cd -> horizontalHeader () -> setSectionResizeMode ( 2, QHeaderView::ResizeToContents );
    ui -> tabela_cd -> horizontalHeader () -> setSectionResizeMode ( 0, QHeaderView::Stretch );
    ui -> tabela_cd -> setHorizontalHeaderLabels ( QStringList () << "NOME" << "PRECO" << "N FAIXAS" );

    //tabela DVD
    ui -> label_dvd -> setStyleSheet( "background: lightgray" );
    ui -> label_dvd -> setAlignment ( Qt::AlignCenter );
    ui -> tabela_dvd -> setStyleSheet ( "QHeaderView::section { background-color:lightgray }" );
    ui -> tabela_dvd -> horizontalHeader () -> setSectionResizeMode ( 1, QHeaderView::ResizeToContents );
    ui -> tabela_dvd -> horizontalHeader () -> setSectionResizeMode ( 2, QHeaderView::ResizeToContents );
    ui -> tabela_dvd -> horizontalHeader () -> setSectionResizeMode ( 0, QHeaderView::Stretch );
    ui -> tabela_dvd -> setHorizontalHeaderLabels ( QStringList () << "NOME" << "PRECO" << "DURACAO" );

/**********************************************************************************************/

    exibeListas ();
}

MainLoja::~MainLoja()
{
    delete ui;
}


/******************************************DOUBLECLICK*****************************************/

void MainLoja::on_tabela_livro_cellDoubleClicked(int row, int column)
{
    Q_UNUSED ( column );
    QMessageBox::StandardButton apagar;
    apagar = QMessageBox::question ( this, tr ( "Loja" ), tr ( "Deseja apagar esse livro?" ), QMessageBox::Yes | QMessageBox::No );

    if ( apagar == QMessageBox::Yes ) {
        if ( row >= 0 && unsigned ( row ) < X.getNumLivro () ) {
            X.excluirLivro ( row );
            exibeListaLivro ();
        }
    }
}

void MainLoja::on_tabela_cd_cellDoubleClicked(int row, int column)
{
    Q_UNUSED ( column );
    QMessageBox::StandardButton apagar;
    apagar = QMessageBox::question ( this, tr ( "Loja" ), tr ( "Deseja apagar esse CD?" ), QMessageBox::Yes | QMessageBox::No );

    if ( apagar == QMessageBox::Yes ) {
        if ( row >= 0 && unsigned ( row ) < X.getNumCD () ) {
            X.excluirCD ( row );
            exibeListaCD ();
        }
    }
}

void MainLoja::on_tabela_dvd_cellDoubleClicked(int row, int column)
{
    Q_UNUSED ( column );
    QMessageBox::StandardButton apagar;
    apagar = QMessageBox::question ( this, tr ( "Loja" ), tr ( "Deseja apagar esse DVD?" ), QMessageBox::Yes | QMessageBox::No );

    if ( apagar == QMessageBox::Yes ) {
        if ( row >= 0 && unsigned ( row ) < X.getNumDVD () ) {
            X.excluirDVD ( row );
            exibeListaDVD ();
        }
    }
}

/**********************************************************************************************/


/*******************************************SLOTS**********************************************/

void MainLoja::on_actionLer_triggered()
{
    QString fileName = QFileDialog::getOpenFileName ( this, "Ler estoque", QString(), "Text Files (*.txt);;C++ Files (*.cpp *.h)");

    if ( !fileName.isEmpty () ) {
        QFile file ( fileName );
        if ( !file.open ( QIODevice::ReadOnly ) ) {
            QMessageBox::critical ( this, tr ( "Error" ), tr ( "Could not open file" ) );
            return;
        }
        X.ler ( fileName.toStdString () );
        exibeListas ();
        file.close ();
    }
}

void MainLoja::on_actionSalvar_triggered()
{
    QString fileName = QFileDialog::getSaveFileName ( this, "Salvar estoque", QString(), "Text Files (*.txt);;C++ Files (*.cpp *.h)");

    if ( !fileName.isEmpty () ) {
        QFile file ( fileName );
        if ( !file.open ( QIODevice::WriteOnly ) ) {
            QMessageBox::critical ( this, tr ( "Error" ), tr ( "Could not open file" ) );
            return;
        } else {
            X.salvar ( fileName.toStdString () );
            file.close ();
        }
    }
}

void MainLoja::on_actionSair_triggered()
{
    QCoreApplication::quit ();
}

void MainLoja::on_actionIncluir_Livro_triggered()
{
    inclLivro -> show ();
    exibeListaLivro ();
}

void MainLoja::on_actionIncluir_CD_triggered()
{
    inclCD -> show ();
    exibeListaCD ();
}

void MainLoja::on_actionIncluir_DVD_triggered()
{
    inclDVD -> show ();
    exibeListaDVD ();
}

void MainLoja::slotIncluirLivro ( QString nome, QString preco, QString autor )
{
    string nomeStr = nome.toStdString ();

    double precoFloat = preco.toFloat ();
    unsigned precoUnsigned = round ( precoFloat * 100.0 );

    string autorStr = autor.toStdString ();

    Livro livro ( nomeStr, precoUnsigned, autorStr );

    if ( livro.getNome () != "" && livro.getPreco () != 0.0 && livro.getAutor () != "" ) {
        X.incluirLivro( livro );
        exibeListaLivro ();
    }
    else {
        QMessageBox::critical ( this, "Livro invalido", QString ( " Nao foi possivel incluir o livro:\n" )
                                + "Nome = " + nome + "\nPreco = " + preco + "\nAutor = " + autor );
    }
}

void MainLoja::slotIncluirCD ( QString nome, QString preco, QString numfaixas )
{   
    string nomeStr = nome.toStdString ();

    double precoFloat = preco.toFloat ();
    unsigned precoUnsigned = round ( precoFloat * 100.0 );

    unsigned numfaixasUnsigned = numfaixas.toInt ();

    CD cd ( nomeStr, precoUnsigned, numfaixasUnsigned );

    if ( cd.getNome () != "" && cd.getPreco () != 0.0 && cd.getNumFaixas () != 0.0 ) {
        X.incluirCD ( cd );
        exibeListaCD ();
    }
    else {
        QMessageBox::critical ( this, "CD invalido", QString ( " Nao foi possivel incluir o CD:\n" )
                                + "Nome = " + nome + "\nPreco = " + preco + "\nNum faixas = " + numfaixas );
    }
}

void MainLoja::slotIncluirDVD ( QString nome, QString preco, QString duracao )
{
    string nomeStr = nome.toStdString ();

    double precoFloat = preco.toFloat ();
    unsigned precoUnsigned = round ( precoFloat * 100.0 );

    unsigned duracaoUnsigned = duracao.toInt ();

    DVD dvd ( nomeStr, precoUnsigned, duracaoUnsigned );

    if ( dvd.getNome () != "" && dvd.getPreco () != 0.0 && dvd.getDuracao () != 0.0 ) {
        X.incluirDVD ( dvd );
        exibeListaDVD ();
    }
    else {
        QMessageBox::critical ( this, "DVD invalido", QString ( " Nao foi possivel incluir o DVD:\n" )
                                + "Nome = " + nome + "\nPreco = " + preco + "\nDuracao = " + duracao );
    }
}

/**********************************************************************************************/


/******************************************EXIBIR**********************************************/

void MainLoja::exibeListaLivro () {
    ui -> tabela_livro -> clearContents ();
    ui -> tabela_livro -> setRowCount ( X.getNumLivro () );

    for ( unsigned i = 0; i < X.getNumLivro (); i++ ) {
        for ( unsigned j = 0; j < 3; j++ ) {
            QTableWidgetItem *prov = new QTableWidgetItem;
            if ( j == 0 ) {
                QString nome = QString::fromStdString ( X.getLivro ( i ).getNome () );
                prov -> setText ( nome );
            }
            if ( j == 1 ) {
                QString preco = QString::number ( X.getLivro ( i ).getPreco (), 'f', 2 );
                prov -> setText ( preco );
                prov -> setTextAlignment ( Qt::AlignRight | Qt::AlignVCenter );
            }
            if ( j == 2 ) {
                QString autor = QString::fromStdString ( X.getLivro ( i ).getAutor () );
                prov -> setText ( autor );
            }
            prov -> setFlags ( Qt::ItemIsSelectable | Qt::ItemIsEnabled );
            ui -> tabela_livro -> setItem ( i, j, prov );
        }
    }
    exibeStatus ();
}

void MainLoja::exibeListaCD () {
    ui -> tabela_cd -> clearContents ();
    ui -> tabela_cd -> setRowCount ( X.getNumCD () );

    for ( unsigned i = 0; i < X.getNumCD (); i++ ) {
        for ( unsigned j = 0; j < 3; j++ ) {
            QTableWidgetItem *prov = new QTableWidgetItem;
            if ( j == 0 ) {
                QString nome = QString::fromStdString ( X.getCD ( i ).getNome () );
                prov -> setText ( nome );
            }
            if ( j == 1 ) {
                QString preco = QString::number ( X.getCD ( i ).getPreco (), 'f', 2 );
                prov -> setText ( preco );
                prov -> setTextAlignment ( Qt::AlignRight | Qt::AlignVCenter );
            }
            if ( j == 2 ) {
                QString numfaixas = QString::number ( X.getCD ( i ).getNumFaixas () );
                prov -> setText ( numfaixas );
                prov -> setTextAlignment ( Qt::AlignCenter );
            }
            prov -> setFlags ( Qt::ItemIsSelectable | Qt::ItemIsEnabled );
            ui -> tabela_cd -> setItem ( i, j, prov );
        }
    }
    exibeStatus ();
}

void MainLoja::exibeListaDVD () {
    ui -> tabela_dvd -> clearContents ();
    ui -> tabela_dvd -> setRowCount ( X.getNumDVD () );

    for ( unsigned i = 0; i < X.getNumDVD (); i++ ) {
        for ( unsigned j = 0; j < 3; j++ ) {
            QTableWidgetItem *prov = new QTableWidgetItem;
            if ( j == 0 ) {
                QString nome = QString::fromStdString ( X.getDVD ( i ).getNome () );
                prov -> setText ( nome );                
            }
            if ( j == 1 ) {
                QString preco = QString::number ( X.getDVD ( i ).getPreco (), 'f', 2 );
                prov -> setText ( preco );
                prov -> setTextAlignment ( Qt::AlignRight | Qt::AlignVCenter );
            }
            if ( j == 2 ) {
                QString duracao = QString::number ( X.getDVD ( i ).getDuracao () );
                prov -> setText ( duracao );
                prov -> setTextAlignment ( Qt::AlignCenter );
            }
            prov -> setFlags ( Qt::ItemIsSelectable | Qt::ItemIsEnabled );
            ui -> tabela_dvd -> setItem ( i, j, prov );
        }
    }
    exibeStatus ();
}

void MainLoja::exibeListas () {
    exibeListaLivro ();
    exibeListaCD ();
    exibeListaDVD ();
}

void MainLoja::exibeStatus () {
    QString total = QString::number ( X.getNumLivro () + X.getNumCD () + X.getNumDVD () );
    total_itens -> setText ( total );
}

/**********************************************************************************************/
