#include <iostream>
#include <cstring>

#include "Poly.h"

using namespace std;

int main ( void ) {
    Poly P1;
    Poly P2 ( 0 );
    Poly Result ( 1 );
    double x;
    unsigned grau;
    char opcao;

    cout << "CALCULADORA DE POLINOMIOS\n";

    P1.ler ( "poly_P1.txt" );
    P2.ler ( "poly_P2.txt" );
    Result.ler ( "poly_result.txt" );

    do {
        do {
        cout << endl;
        cout << "P1:     " << P1 << endl;
        cout << "P2:     " << P2 << endl;
        cout << "Result: " << Result << endl;
        cout << "Digite sua opcao:\n";
        cout << "< - Entrar um novo polinomio\n";
        cout << "+ - Somar os polinomios\n";
        cout << "- - Subtrair os polinomios\n";
        cout << "* - Multiplicar os polinomios\n";
        cout << "x - Calcular o ultimo polinomio (Result) para um valor de x\n";
        cout << "i - Inverter o sinal do ultimo polinomio (Result)\n";
        cout << "t - Trocar os polinomios (P1->P2 P2->Result Result->P1)\n";
        cout << "q - Terminar\n";
        cin >> opcao;
        opcao = tolower(opcao);

        } while ( strchr ( "<+-*xitq", opcao ) == nullptr );

        if ( strchr ( "<+-*/%x", opcao ) != nullptr ) {
            P1 = P2;
            P2 = Result;
        }
        else if ( opcao == 't' ) {
            Poly aux ( Result );
            Result = P2;
            P2 = P1;
            P1 = aux;
        }

        switch ( opcao ) {
            case '<':
            cout << "Grau do polinomio: "  ;
            cin >> grau;
            Result.recriar ( grau );
            cout << "Coeficientes do polinomio:\n";
            cin >> Result;
            break;
            case '+':
                Result = P1 + P2;
                break;
            case '-':
                Result = P1 - P2;
                break;
            case '*':
                Result = P1 * P2;
                break;
            case 'x':
                cout << "Valor de x: ";
                cin >> x;
                Result.recriar ( 0 );
                Result.setCoef ( 0, P2 ( x ) );
                break;
            case 'i':
                Result = -Result;
                break;
            case 't':
            case 'q':
                break;
            default:
                cerr << "Opcao desconhecida\n";
                Result = Poly ();
                break;
        }

        P1.salvar ( "polinomio_P1.txt" );
        P2.salvar ( "polinomio_P2.txt" );
        Result.salvar ( "polinomio_result.txt" );

    } while ( opcao != 'q' );

    return 0;
}
