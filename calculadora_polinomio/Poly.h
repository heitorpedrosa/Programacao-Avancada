#ifndef _POLY_H_
#define _POLY_H_

#include <iostream>

using namespace std;

class Poly {
private:
    unsigned D;
    double *polinomio;

    void criar ( unsigned Num );
    void copiar ( const Poly &P ); ///copia

public:
    void limpar (); ///liberacao de memoria
    void recriar ( unsigned Num ); ///redefinir um polinomio **FALTA AJEITAR**

    ///Construtores;
    inline Poly () : D ( 0 ), polinomio ( nullptr ) {} ///default;
    inline Poly ( const Poly &P ) { copiar ( P ); } ///copia;
    explicit Poly ( unsigned Num ); ///especifico
    inline ~Poly () { limpar () ; } ///destrutor

    ///Sobrecarga;
    void operator= ( const Poly &P ); ///atribuir um polinomio a outro
    inline double operator[] ( unsigned i ) const { return getCoef ( i ); } ///P [ 0 ] == P.getCoef ( 0 );
    inline double operator() ( double X ) const { return getValor ( X ); } ///P ( 1.5 ) == P.getValor ( 1.5 );
    Poly operator* ( const Poly &P ) const; ///multiplicacao
    Poly operator+ ( const Poly &P ) const; ///adicao
    Poly operator- ( const Poly &P ) const; ///subtracao
    Poly operator- () const; ///negativo do polinomio

    ///Consulta;
    inline int getGrau () const { return ( int ( D ) - 1 ); } ///retorna o grau
    double getCoef ( unsigned i ) const; ///retorna o coeficiente da posicao i
    double getValor ( double X ) const; ///retorna o valor do polinomio para o valor x
    void setCoef ( unsigned i, double C ); ///alterar o valor do coeficiente da posicao i

    friend ostream &operator<< ( ostream &Out, const Poly &P ); ///cout;
    friend istream &operator>> ( istream &In, Poly &P ); ///cin;

    ///Arquivo;
    bool ler ( string S );
    bool salvar ( string S );
};

#endif //_POLY_H_
