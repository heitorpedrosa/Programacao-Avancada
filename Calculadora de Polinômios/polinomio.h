#ifndef _POLY_H_
#define _POLY_H_

#include <iostream>

using namespace std;

class Poly {
private:
    unsigned D;
    double *polinomio;

    void criar ( unsigned Num );
    void copiar ( const Poly &P );

public:
    void limpar ();
    void recriar ( unsigned Num );

    ///Construtores;
    inline Poly () : D ( 0 ), polinomio ( nullptr ) {}
    inline Poly ( const Poly &P ) { copiar ( P ); }
    explicit Poly ( unsigned Num );
    inline ~Poly () { limpar () ; }

    ///Sobrecarga;
    void operator= ( const Poly &P );
    inline double operator[] ( unsigned i ) const { return getCoef ( i ); }
    inline double operator() ( double X ) const { return getValor ( X ); }
    Poly operator* ( const Poly &P ) const;
    Poly operator+ ( const Poly &P ) const;
    Poly operator- ( const Poly &P ) const;
    Poly operator- () const;

    ///Consulta;
    inline int getGrau () const { return ( int ( D ) - 1 ); }
    double getCoef ( unsigned i ) const;
    double getValor ( double X ) const;
    void setCoef ( unsigned i, double C );

    friend ostream &operator<< ( ostream &Out, const Poly &P ); ///cout;
    friend istream &operator>> ( istream &In, Poly &P ); ///cin;

    ///Arquivamento;
    bool ler ( string S );
    bool salvar ( string S );
};

#endif //_POLY_H_
