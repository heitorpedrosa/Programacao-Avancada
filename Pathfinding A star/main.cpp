#include <iostream>
#include <cmath>
#include <chrono>
#include "labirinto.h"

using namespace std;

int main ( void ) {
    Labirinto L;
    int opcao;

    do {
        cout << endl;
        L.imprimir ();
        do {
            printf ( "\n1 - Gerar mapa\n2 - Ler mapa\n3 - Definir origem\n4 - Definir destino\n5 - Calcular caminho\n0 - Sair\nOPCAO: " );
            cin >> opcao;
        } while ( opcao < 0 || opcao > 5 );

        switch ( opcao ) {
            case 1:
                if ( !L.gerar () ) cerr << "Erro na geracao do mapa\n";
                break;
            case 2:
                {
                    string arq;
                    do {
                        cout << "ARQUIVO (sem espacos): ";
                        cin >> arq;
                    } while ( arq == "" );

                    if ( !L.ler ( arq ) ) cerr << "Erro na leitura do arquivo " << arq << endl;
                }
                break;
            case 3:
                if ( L.empty () ) cerr << "O mapa estah vazio..." << endl;
                else {
                    Coord O;
                    do {
                        cout << "ORIGEM (lin col): ";
                        cin >> O;
                    } while ( !L.setOrigem ( O ) );
                }
                break;
            case 4:
                if ( L.empty () ) cerr << "O mapa estah vazio..." << endl;
                else {
                    Coord D;
                    do {
                        cout << "DESTINO (lin col): ";
                        cin >> D;
                    } while ( !L.setDestino ( D ) );
                }
                break;
            case 5:
                if ( L.empty () || !L.origDestDefinidos () ) cerr << "Mapa ou caminho indefinido..." << endl;
                else {
                    double comprCaminho, deltaT;
                    int profCaminho, numA, numF;

                    {
                        using namespace chrono;

                        steady_clock::time_point t1 = steady_clock::now ();

                        comprCaminho = L.calculaCaminho ( profCaminho, numA, numF );

                        steady_clock::time_point t2 = steady_clock::now ();

                        duration <double> time_span = duration_cast < duration <double> > ( t2 - t1 );

                        deltaT = 1000 * time_span.count ();
                    }

                    if ( comprCaminho >= 0.0 ) printf ( "\nCaminho encontrado!\nComprimento = %f\nProfundidade = %d\n", comprCaminho, profCaminho );
                    else cout << "Nao existe caminho..." << endl;

                    printf ( "Num de nos em fechado = %d\nNum de nos em aberto = %d\n", numF, numA );
                    cout << "Tempo = " << deltaT << "ms" << endl;
                }
                break;
            default:
                break;
        }
    } while ( opcao != 0 );
}
