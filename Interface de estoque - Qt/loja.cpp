#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cmath>
#include <limits>
#include "loja.h"

using namespace std;

void Produto::digitar () {
    do {
        cout << "Nome: ";
        getline ( cin, nome );
    } while ( nome == "" );

    double Pr;
    do {
        cout << "Preco (##.##): ";
        cin >> Pr;
    } while ( Pr <= 0.0 );
    cin.ignore ();
    preco = ( unsigned )round(100.0 * Pr);
}

bool Produto::ler ( istream &input ) {
    double Pr;

    input.ignore ( numeric_limits <streamsize>::max (), '"' );
    getline ( input, nome,'"' );
    input.ignore ( numeric_limits <streamsize>::max (), '$' );

    input >> Pr;

    preco = ( unsigned ) round ( 100.0 * Pr );

    if ( nome == "" || preco == 0 ) {
    nome = "";
    preco = 0;
    return false;
    }
    return true;
}

void Produto::salvar ( ostream &output ) const {
    output << '"' << nome << '"' << ";$" << fixed << setprecision ( 2 ) << double ( preco ) / 100.0;
}

void Livro::digitar () {
    Produto::digitar ();
    do {
        cout << "Autor: ";
        getline ( cin, autor );
    } while ( autor == "" );
}

bool Livro::ler ( istream &input ) {
    char opcao;
    input >> opcao;
    if ( opcao != 'L' ) {
        *this = Livro ();
        return false;
    }
    input.ignore ( numeric_limits<streamsize>::max (), ':' );
    if ( !Produto::ler ( input ) ) {
        *this = Livro ();
        return false;
    }

    input.ignore ( numeric_limits <streamsize>::max (), '"' );

    getline ( input, autor, '"' );

    input.ignore ();
    if ( autor  ==  "" ) {
        *this = Livro ();
        return false;
    }
    return true;
}

void Livro::salvar ( ostream &output ) const {
    output << "L: ";
    Produto::salvar ( output );
    output << ';' << '"' << autor << '"';
}

void CD::digitar () {
    Produto::digitar ();
    do {
        cout << "Numero de faixas: ";
        cin >> nfaixas;
    } while ( nfaixas  ==  0 );
    cin.ignore ();
}

bool CD::ler ( istream &input ) {
    char opcao;
    input >> opcao;
    if ( opcao != 'C' ) {
        *this = CD ();
        return false;
    }

    input.ignore ( numeric_limits <streamsize>::max (), ':' );

    if ( !Produto::ler ( input ) ) {
        *this = CD ();
        return false;
    }

    input.ignore ( numeric_limits <streamsize>::max (), ';' );

    input >> nfaixas;

    input.ignore ();
    if ( nfaixas  ==  0 ) {
        *this = CD ();
        return false;
    }
    return true;
}

void CD::salvar ( ostream &output ) const {
    output << "C: ";
    Produto::salvar ( output );
    output << ';' << nfaixas;
}

void DVD::digitar () {
    Produto::digitar ();
    do {
        cout << "Duracao: ";
        cin >> duracao;
    } while ( duracao  ==  0 );
    cin.ignore ();
}

bool DVD::ler ( istream &input ) {
    char opcao;
    input >> opcao;
    if ( opcao != 'D' ) {
        *this = DVD ();
        return false;
    }

    input.ignore ( numeric_limits <streamsize>::max (), ':' );

    if ( !Produto::ler ( input ) ) {
        *this = DVD ();
        return false;
    }

    input.ignore ( numeric_limits <streamsize>::max (), ';' );

    input >> duracao;

    input.ignore ();
    if ( duracao  ==  0 ) {
        *this = DVD ();
        return false;
    }
    return true;
}

void DVD::salvar ( ostream &output ) const {
    output << "D: ";
    Produto::salvar ( output );
    output << ';' << duracao;
}

Livro Loja::getLivro ( unsigned id ) const {
    if ( LL.empty () || id >= LL.size () ) return Livro();
    return LL [ id ];
}

CD Loja::getCD ( unsigned id ) const {
    if ( LC.empty () || id >= LC.size () ) return CD();
    return LC [ id ];
}

DVD Loja::getDVD ( unsigned id ) const {
    if ( LD.empty () || id >= LD.size () ) return DVD();
    return LD [ id ];
}

bool Loja::excluirLivro ( unsigned id ) {
  if ( LL.empty () || id >= LL.size () ) return false;
  LL.erase ( LL.begin () + id );
  return true;
}

bool Loja::excluirCD ( unsigned id ) {
    if ( LC.empty () || id >= LC.size () ) return false;
    LC.erase ( LC.begin () + id );
    return true;
}

bool Loja::excluirDVD ( unsigned id ) {
    if ( LD.empty () || id >= LD.size () ) return false;
    LD.erase ( LD.begin () + id );
    return true;
}

void Loja::imprimir() const {
    cout << ">> LIVROS:" << endl;
    for (unsigned i = 0; i < LL.size (); i++) cout << i << " ) " << LL [ i ] << endl;

    cout << ">> CDS:" << endl;
    for (unsigned i = 0; i < LC.size (); i++) cout << i << " ) " << LC [ i ] << endl;

    cout << ">> DVDS:" << endl;
    for (unsigned i = 0; i < LD.size (); i++) cout << i << " ) " << LD [ i ] << endl;
}

bool Loja::ler ( const string &arq ) {
    ifstream input ( arq.c_str () );
    if ( !input.is_open () ) return false;

    string pS;
    unsigned NN;
    Livro L;
    CD C;
    DVD D;

    input >> pS >> NN;
    input.ignore ();
    if ( pS != "LISTALIVRO" ) {
    input.close ();
    return false;
    }
    LL.clear ();
    for (unsigned i = 0; i < NN; i++ ) {
        if ( !L.ler ( input ) ) {
          LL.clear ();
          input.close ();
          return false;
        }
        LL.push_back ( L );
    }

    input >> pS >> NN;
    input.ignore ();
    if ( pS != "LISTACD" ) {
        input.close ();
        return false;
    }
    LC.clear ();
    for ( unsigned i = 0; i < NN; i++ ) {
        if ( !C.ler ( input ) ) {
          LC.clear ();
          input.close ();
          return false;
        }
        LC.push_back ( C );
    }

    input >> pS >> NN;
    input.ignore ();
    if ( pS != "LISTADVD" ) {
        input.close ();
        return false;
    }
    LD.clear ();
    for ( unsigned i = 0; i < NN; i++ ) {
        if ( !D.ler ( input ) ) {
          LD.clear ();
          input.close ();
          return false;
        }
        LD.push_back ( D );
    }

    input.close ();
    return true;
}

bool Loja::salvar ( const string &arq ) const {
    ofstream output ( arq.c_str () );
    if ( !output.is_open() ) return false;

    output << "LISTALIVRO " << LL.size ()  << endl;
    for ( unsigned i = 0; i < LL.size (); i++ ) output << LL [ i ] << endl;

    output << "LISTACD " << LC.size ()  << endl;
    for ( unsigned i = 0; i < LC.size (); i++ ) output << LC [ i ] << endl;

    output << "LISTADVD " << LD.size ()  << endl;
    for ( unsigned i = 0; i < LD.size (); i++) output << LD [ i ] << endl;

    output.close ();
    return true;
}
