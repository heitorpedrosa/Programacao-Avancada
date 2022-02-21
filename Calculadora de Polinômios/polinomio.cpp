#include <iostream>
#include <fstream>
#include <cmath>

#include "Poly.h"

using namespace std;

void Poly::limpar () {
    if ( polinomio != nullptr ) delete [] polinomio;
    D = 0;
    polinomio = nullptr;
}

void Poly::criar ( unsigned Num ) {
    D = Num;
    polinomio = ( D > 0 ? new double [ D ] : nullptr );
}

void Poly::copiar ( const Poly &P ) {
    criar ( P.D );
    for ( unsigned i = 0; i < D; i++ ) polinomio [ i ] = P.polinomio [ i ];
}

void Poly::recriar ( unsigned Num ) {
    int d = Num + 1;
    limpar ();
    criar ( d );
}

Poly::Poly ( unsigned Num ) {
    int d = Num + 1;
    criar ( d );
    if ( D == 1 ) polinomio [ 0 ] = 0.0;
    else for ( int i = 0 ; i < int ( D ); i++ ) polinomio [ i ] = ( i == getGrau () ? 1.0 : 0.0 );
}

void Poly::operator= ( const Poly &P ) {
    if ( this != &P ) {
        if ( this -> D == P.D ) {
            for ( unsigned i = 0; i < D; i++ ) polinomio [ i ] = P.polinomio [ i ];
        }
        else {
            limpar ();
            copiar ( P );
        }
    }
}

Poly Poly::operator* ( const Poly &P ) const {
    if ( D == 0 || P.D == 0 ) {
        return Poly ();
    }
    else {
        if ( ( D == 1 && polinomio [ 0 ] == 0 ) || ( P.D == 1 && P.polinomio [ 0 ] == 0 ) ) {
            return Poly ( 0 );
        }
        else {
            int grau = getGrau () + P.getGrau ();
            Poly resultado ( grau );
            for ( unsigned i = 0; i < D; i++ ) {
                for ( unsigned j = 0; j < P.D; j++ ) {
                    resultado.polinomio [ i + j ] += polinomio [ i ] * P.polinomio [ j ];
                }
            }
            resultado.polinomio [ grau ] -= 1;
            return resultado;
        }
    }
}

Poly Poly::operator+ ( const Poly &P ) const {
    if ( D == 0 ) return P;
    else if ( P.D == 0 ) return *this;
    else {
        if ( D == P.D ) {
            int grau = getGrau ();
            Poly resultado ( grau );
            int aux = 0;
            bool teste = false;
            for ( int i = grau; i >= 0; i-- ) {
                if ( polinomio [ i ] + P.polinomio [ i ] == 0 && !teste && i != 0 ) aux++;
                else teste = true;
                resultado.polinomio [ i ] = polinomio [ i ] + P.polinomio [ i ];
            }
            if ( aux != 0 ) {
                int d = grau - aux;
                Poly resultado_menor_grau ( d );

                for ( int i = 0; i <= d; i++ ) resultado_menor_grau.setCoef ( i, resultado.polinomio [ i ] );
                return resultado_menor_grau;
            }
            else return resultado;
        }
        else {
            int grau = int ( ( D > P.D ? D : P.D ) ) - 1;
            int menor_d = int ( ( D < P.D ? D : P.D ) );

            Poly resultado ( grau );
            if ( D > P.D ) resultado = *this;
            else resultado = P;

            for ( int i = 0; i < menor_d; i++ ) resultado.setCoef ( i, polinomio [ i ] + P.polinomio [ i ] );
            return resultado;
        }
    }
}

Poly Poly::operator- ( const Poly &P ) const {
    if ( D == 0 ) return -P;
    else if ( P.D == 0 ) return *this;
    else {
        if ( D == P.D ) {
            int grau = getGrau ();
            Poly resultado ( grau );
            int aux = 0;
            bool teste = false;
            for ( int i = grau; i >= 0; i-- ) {
                if ( polinomio [ i ] - P.polinomio [ i ] == 0 && !teste && i != 0 ) aux++;
                else teste = true;
                resultado.polinomio [ i ] = polinomio [ i ] - P.polinomio [ i ];
            }
            if ( aux != 0 ) {
                int d = grau - aux;
                Poly resultado_menor_grau ( d );

                for ( int i = 0; i <= d; i++ ) resultado_menor_grau.setCoef ( i, resultado.polinomio [ i ] );
                return resultado_menor_grau;
            }
            else return resultado;
        }
        else {
            int grau = int ( ( D > P.D ? D : P.D ) ) - 1;
            int menor_d = int ( ( D < P.D ? D : P.D ) );

            Poly resultado ( grau );
            if ( D > P.D ) resultado = *this;
            else resultado = -P;

            for ( int i = 0; i < menor_d; i++ ) resultado.setCoef ( i, polinomio [ i ] - P.polinomio [ i ] );
            return resultado;
        }
    }
}

Poly Poly::operator- () const {
    if ( D == 0 ) {
        return Poly ();
    }
    else {
        int grau = getGrau ();
        Poly resultado ( grau );
        for ( unsigned i = 0; i < D; i++ ) resultado.polinomio [ i ] = -polinomio [ i ];
        return resultado;
    }
}

double Poly::getCoef ( unsigned i ) const {
    if ( i >= D ) return 0.0;
    else return polinomio [ i ];
}

double Poly::getValor ( double X ) const {
    if ( D == 0 ) return 0.0;
    else {
        double soma = 0;
        for ( int i = getGrau (); i >= 0; i-- ) soma += polinomio [ i ] * pow ( X, i );
        return soma;
    }
}

void Poly::setCoef ( unsigned i, double C ) {
    if ( i >= D ) cerr << "Indice invalido" << endl;
    else if ( int ( i ) == getGrau () && C == 0 ) cerr << "Coeficiente invalido" << endl;
    else polinomio [ i ] = C;
}

ostream &operator<< ( ostream &output, const Poly &P ) {
    if ( P.D == 0 ) {}
    else if ( P.D == 1 ) output << P.polinomio [ 0 ];
    else {
        for ( int i = P.getGrau (); i >= 0; i-- ) {
            if ( P.polinomio [ i ] == 0 ) {}
            else {
                if ( i == P.getGrau () ) {
                    if ( i > 1 ) {
                        if ( fabs ( P.polinomio [ i ] ) == 1 ) {
                            if ( P.polinomio [ i ] < 0 ) output << "-x^" << i;
                            else output << "x^" << i;
                        }
                        else output << P.polinomio [ i ] << "*x^" << i;
                    }
                    else {
                        if ( fabs ( P.polinomio [ i ] ) == 1 ) {
                            if ( P. polinomio [ i ] < 0 ) output << "-x";
                            else output << "x";
                        }
                        else output << P.polinomio [ i ] << "*x";
                    }
                }
                else {
                    if ( i != 0 ) {
                        if ( i > 1 ) {
                            if ( fabs ( P.polinomio [ i ] ) == 1 ) output << ( P.polinomio [ i ] > 0 ? '+' : '-' ) << "x^" << i;
                            else output << ( P.polinomio [ i ] > 0 ? '+' : '-' ) << fabs ( P.polinomio [ i ] ) << "*x^" << i;
                        }
                        else {
                            if ( fabs ( P.polinomio [ i ] ) == 1 ) output << ( P.polinomio [ i ] > 0 ? '+' : '-' ) << "x";
                            else output << ( P.polinomio [ i ] > 0 ? '+' : '-' ) << fabs ( P.polinomio [ i ] ) << "*x";
                        }
                    }
                    else output << ( P.polinomio [ i ] > 0 ? '+' : '-' ) << fabs ( P.polinomio [ i ] );
                }
            }
        }
    }
    return output;
}

istream &operator>> ( istream &input, Poly &P ) {
    if ( P.D == 0 ) cerr << "Polinomio vazio nao tem coeficiente";
    for ( int i = P.getGrau (); i >= 0; i-- ) {
        cout << "x^" << i << ":" << endl;
        input >> P.polinomio [ i ];
        if ( i == P.getGrau () && P.polinomio [ i ] == 0 && i != 0 ) {
            do {
                cerr << "O coeficiente de maior nao pode ser 0 " << endl;
                cout << "x^" << i << ":" << endl;
                input >> P.polinomio [ i ];
            } while ( P.polinomio [ i ] == 0 );
        }
    }
    return input;
}

bool Poly::ler ( string S ) {
    ifstream input ( S );
    string poly;
    int d;
    int aux;
    int count = 0;
    double teste;

    input >> poly;
    input >> d;
    aux = input.tellg ();

    while ( input >> teste ) {
        count++;
    }

    input.clear ();
    input.seekg ( aux );

    if ( poly != "POLY" || d < 0 || d != count || teste == 0 ) {
        input.close ();
        return false;
    }
    else {
        criar ( d );
        for ( int i = 0; i < d; i++ ) input >> polinomio [ i ];
        input.close ();
        return true;
    }
}

bool Poly::salvar ( string S ) {
    ofstream output ( S );
    output << "POLY " << D << endl;
    if ( D == 0 ) {}
    for ( unsigned i = 0; i < D; i++ ) output << polinomio [ i ] << " ";

    if ( output.good () ) return true;
    else return false;
}
