#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <string>
#include <time.h>
#include <cmath>
#include <list>
#include <algorithm>
#include <vector>

#include "labirinto.h"

using namespace std;

string estadoCel2string ( EstadoCel E ) {
    switch ( E ) {
        case EstadoCel::LIVRE:
            return "  ";
        case EstadoCel::OBSTACULO:
            return "##";
        case EstadoCel::ORIGEM:
            return "Or";
        case EstadoCel::DESTINO:
            return "De";
        case EstadoCel::CAMINHO:
            return "..";
        default:
            break;
    }
    return "??";
}

istream& operator>> ( istream& input, Coord& C ) {
    input >> C.lin >> C.col;
    return input;
}

ostream& operator<< ( ostream& output, const Coord& C ) {
    output << C.lin << ';' << C.col;
    return output;
}

void Noh::heuristica ( Coord& aux ) {
    double deltaX, deltaY;

    deltaX = abs ( pos.lin - aux.lin );
    deltaY = abs ( pos.col - aux.col );

    h = ( sqrt ( 2 ) * min ( deltaX, deltaY ) + abs ( deltaX - deltaY ) );
}

void Labirinto::clear () {
    NL = NC = 0;
    mapa.clear();
    orig = dest = Coord();
}

void Labirinto::limpaCaminho () {
    if ( !empty () ) {
        for ( unsigned i = 0; i < NL; i++ ) {
            for ( unsigned j = 0; j < NC; j++ ) {
                if ( at ( i, j ) == EstadoCel::CAMINHO ) set ( i, j ) = EstadoCel::LIVRE;
            }
        }
    }
}

bool Labirinto::ler ( const string& nome_arq ) {
    clear();

    ifstream arq ( nome_arq.c_str () );
    if ( !arq.is_open () ) return false;

    string prov;
    int numL, numC;
    int valor;

    arq >> prov >> numL >> numC;

    if ( prov != "LABIRINTO" || numL < ALTURA_MIN_MAPA || numL > ALTURA_MAX_MAPA || numC < LARGURA_MIN_MAPA || numC > LARGURA_MAX_MAPA ) {
        arq.close();
        return false;
    }

    NL = numL;
    NC = numC;
    mapa.resize ( NL * NC );

    for ( unsigned i = 0; i < NL; i++ ) {
        for ( unsigned j = 0; j < NC; j++ ) {
            arq >> valor;
            set ( i, j ) = ( valor == 0 ? EstadoCel::OBSTACULO : EstadoCel::LIVRE );
        }
    }
    arq.close ();
    return true;
}

bool Labirinto::salvar ( const string& nome_arq ) const {
    if ( empty () ) return false;

    ofstream arq ( nome_arq.c_str () );
    if ( !arq.is_open () ) return false;

    arq << "LABIRINTO " << NL << ' ' << NC << endl;

    for ( unsigned i = 0; i < NL; i++ ) {
        for ( unsigned j = 0;  j < NC; j++ ) {
            arq << ( at ( i, j ) == EstadoCel::OBSTACULO ? 0 : 1 ) << ' ';
        }
        arq << endl;
    }

    arq.close ();
    return true;
}

bool Labirinto::gerar ( unsigned numL, unsigned numC, double perc_obst ) {
    clear();

    srand ( time ( NULL ) );

    if ( perc_obst <= 0.0 ) {
        perc_obst = PERC_MIN_OBST + ( PERC_MAX_OBST-PERC_MIN_OBST ) * ( rand () / double ( RAND_MAX ) );
    }

    if ( numL < ALTURA_MIN_MAPA || numL > ALTURA_MAX_MAPA || numC < LARGURA_MIN_MAPA || numC > LARGURA_MAX_MAPA || perc_obst < PERC_MIN_OBST || perc_obst > PERC_MAX_OBST ) return false;

    NL = numL;
    NC = numC;

    mapa.resize ( NL * NC );

    bool obstaculo;
    for ( unsigned i = 0; i < NL; i++ ) {
        for ( unsigned j = 0; j < NC; j++ ) {
            obstaculo = ( rand () / double ( RAND_MAX ) <= perc_obst );
            set ( i, j ) = ( obstaculo ? EstadoCel::OBSTACULO : EstadoCel::LIVRE );
        }
    }

    return true;
}

bool Labirinto::coordValida ( const Coord& C ) const {
    if ( !C.valida () ) return false;
    if ( C.lin >= int ( NL ) ) return false;
    if ( C.col >= int ( NC ) ) return false;
    return true;
}

bool Labirinto::celulaLivre ( const Coord& C ) const {
    if ( !coordValida ( C ) ) return false;
    if ( at ( C ) == EstadoCel::OBSTACULO ) return false;
    return true;
}

bool Labirinto::movimentoValido ( const Coord& Orig, const Coord& Dest ) const {
    if ( !celulaLivre ( Orig ) ) return false;
    if ( !celulaLivre ( Dest ) ) return false;

    Coord delta = abs ( Dest - Orig );
    if ( delta.lin > 1 || delta.col > 1 ) return false;

    if ( !celulaLivre ( Coord ( Orig.lin, Dest.col ) ) ) return false;
    if ( !celulaLivre ( Coord ( Dest.lin, Orig.col ) ) ) return false;

    return true;
}

bool Labirinto::setOrigem ( const Coord& C ) {
    if ( !celulaLivre ( C ) ) return false;

    if ( C == orig ) return true;

    limpaCaminho ();

    if ( coordValida ( orig ) ) set ( orig ) = EstadoCel::LIVRE;

    orig = C;

    set ( orig ) = EstadoCel::ORIGEM;

    return true;
}

bool Labirinto::setDestino ( const Coord& C ) {
    if ( !celulaLivre ( C ) ) return false;

    if ( C == dest ) return true;

    limpaCaminho ();

    if ( coordValida ( dest ) ) set ( dest ) = EstadoCel::LIVRE;

    dest = C;

    set ( dest ) = EstadoCel::DESTINO;

    return true;
}

void Labirinto::imprimir () const {
    if ( empty () ) {
        cout << "+------------+" << endl;
        cout << "| MAPA VAZIO |" << endl;
        cout << "+------------+" << endl;
        return;
    }

    unsigned i, j;

    cout << "    ";
    for ( j = 0; j < NC; j++ ) {
        cout << setfill ( '0' ) << setw ( 2 ) << j << setfill ( ' ' ) << setw ( 0 ) << ' ' ;
    }
    cout << endl;

    cout << "   +";
    for ( j = 0; j < NC; j++ ) cout << "--+" ;
    cout << endl;

    for ( i = 0; i < NL; i++ ) {
        cout << setfill ( '0' ) << setw ( 2 ) << i << setfill ( ' ' ) << setw ( 0 ) << " |" ;
        for ( j = 0; j < NC; j++ ) {
            cout << estadoCel2string ( at ( i, j ) ) << '|' ;
        }
        cout << endl;

        cout << "   +";
        for ( j = 0; j < NC; j++ ) cout << "--+" ;
        cout << endl;
    }
}

double Labirinto::calculaCaminho ( int& NC, int& NA, int& NF ) {
    if ( empty () || !origDestDefinidos () ) {
        NC = NA = NF = -1;
        return -1.0;
    }

    limpaCaminho ();

    if ( orig == dest ) {
        NC = 0;
        NA = NF = 0;
        return 0.0;
    }

    list <Noh> Aberto;
    list <Noh> Fechado;
    list <Noh>::iterator oldF;
    list <Noh>::iterator oldA;
    list <Noh>::iterator it;
    list <Noh>::iterator itr;

    Coord dir, prox, anterior, destino;
    destino = getDest ();

    Noh atual, suc;

    atual.pos = getOrig ();
    atual.g = 0.0;
    atual.heuristica ( destino );

    Aberto.push_front ( atual );

    do {
        atual = Aberto.front ();
        Aberto.pop_front ();
        Fechado.push_front ( atual );

        if ( atual.pos != destino ) {
            for ( dir.lin = -1; dir.lin <= 1; dir.lin++ ) {
                for ( dir.col = -1; dir.col <= 1; dir.col++ ) {
                    if ( (atual.pos + dir ) != atual.pos ) {
                        prox = atual.pos + dir;
                        if ( movimentoValido ( atual.pos, prox ) ) {
                            suc.pos = prox;
                            suc.ant = atual.pos;
                            suc.g = atual.g + norm ( dir );
                            suc.heuristica ( destino );

                            oldF = find ( Fechado.begin (), Fechado.end (), suc );

                            if ( oldF != Fechado.end () ) {
                                if ( suc.custoF () < oldF -> custoF() ) {
                                    Fechado.remove ( *oldF );
                                    oldF = Fechado.end ();
                                }
                            }
                            if ( oldF == Fechado.end () ) {
                                oldA = find ( Aberto.begin (), Aberto.end (), suc );
                                if ( oldA != Aberto.end () ) {
                                    if ( suc.custoF () < oldA -> custoF () ) {
                                        Aberto.remove ( *oldA );
                                        oldA = Aberto.end ();
                                    }
                                }
                            }
                            if ( oldF == Fechado.end () && oldA == Aberto.end () ) {
                                itr = find_if ( Aberto.begin (), Aberto.end (), Noh ( suc.custoF () ) );
                                Aberto.insert ( itr, suc );
                            }
                        }
                    }
                }
            }
        }
    } while ( !( Aberto.empty () ) && atual.pos != destino );

    NA = Aberto.size ();
    NF = Fechado.size ();

    if ( atual.pos != destino ) {
        NC = -1.0;
        return -1.0;
    }
    else {
        double comprimento = atual.g;
        NC = 1;
        while ( atual.ant != getOrig () ) {
            set ( atual.ant.lin , atual.ant.col ) = EstadoCel::CAMINHO;
            anterior = atual.ant;
            itr = find_if ( Fechado.begin (), Fechado.end (), [ &anterior ]( const Noh &noh ) { return noh.pos == anterior; } );
            atual = *itr;
            NC++;
        }
        return comprimento;
    }
}
