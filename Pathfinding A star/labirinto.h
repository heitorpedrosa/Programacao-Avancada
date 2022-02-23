#ifndef _LABIRINTO_H_
#define _LABIRINTO_H_

#include <cmath>
#include <fstream>
#include <vector>

using namespace std;

#define LARGURA_MIN_MAPA 10
#define LARGURA_MED_MAPA 25
#define LARGURA_MAX_MAPA 50

#define ALTURA_MIN_MAPA 5
#define ALTURA_MED_MAPA 10
#define ALTURA_MAX_MAPA 20

#define PERC_MIN_OBST 0.05
#define PERC_MAX_OBST 0.50

struct Coord {
    public:
      int lin, col;

      inline Coord (): lin ( -1 ), col ( -1 ) {}
      inline Coord ( unsigned L, unsigned C ): lin ( L ), col ( C ) {}

      inline bool valida () const { return lin >= 0 && col >= 0; }

      inline bool operator== ( const Coord& C ) const { return lin == C.lin && col == C.col; }
      inline bool operator!= ( const Coord& C ) const { return !operator== ( C ); }

      inline Coord operator+ ( const Coord& C ) const { return Coord ( lin + C.lin, col + C.col ); }
      inline Coord operator- ( const Coord& C ) const { return Coord ( lin - C.lin, col - C.col ); }
};

istream& operator>> ( istream& input, Coord& C );
ostream& operator<< ( ostream& output, const Coord& C);

inline Coord abs ( const Coord& C ) { return Coord ( abs ( C.lin ), abs ( C.col ) ); }

inline double norm ( const Coord& C ) { return sqrt ( C.lin * C.lin + C.col * C.col ); }

enum class EstadoCel {
  LIVRE,
  OBSTACULO,
  ORIGEM,
  DESTINO,
  CAMINHO
};

string estadoCel2string ( EstadoCel E );

class Noh {
    public:
        Coord pos, ant;
        double g, h, valor;

        inline Noh ( double V ): valor ( V ) {}
        bool operator() ( Noh noh ) { return noh.custoF() > valor; }
        inline bool operator== ( Noh noh ) const { return pos == noh.pos; }

        void heuristica ( Coord& aux );

        inline double custoF () { return ( g + h ); }

        inline Noh (): pos(), ant(), g ( 0.0 ), h ( 0.0 ) {}
        inline ~Noh () {}
};

class Labirinto {
    private:
      unsigned int NL, NC;

      vector <EstadoCel> mapa;

      Coord orig, dest;

      inline EstadoCel& set ( unsigned i, unsigned j ) { return mapa.at ( NC * i + j ); }
      inline EstadoCel& set ( const Coord& C ) { return set ( C.lin, C.col ); }

    public:
      inline Labirinto (): NL ( 0 ), NC ( 0 ), mapa (), orig (), dest () {}

      void clear ();

      void limpaCaminho ();

      inline unsigned getNumLin () const { return NL; }
      inline unsigned getNumCol () const { return NC; }
      inline Coord getOrig () const { return orig; }
      inline Coord getDest () const { return dest; }

      bool ler ( const string& nome_arq );
      bool salvar ( const string& nome_arq ) const;

      bool gerar ( unsigned numL = ALTURA_MED_MAPA, unsigned numC = LARGURA_MED_MAPA, double perc_obst = 0.0 );

      inline Labirinto ( unsigned numL, unsigned numC ) { gerar ( numL, numC ); }

      inline Labirinto ( const string& nome_arq ) { ler ( nome_arq ); }

      inline ~Labirinto () {}

      inline EstadoCel at ( unsigned i, unsigned j ) const { return mapa.at ( NC * i + j ); }

      inline EstadoCel at ( const Coord& C ) const { return at ( C.lin, C.col ); }

      inline EstadoCel operator()( unsigned i, unsigned j) const { return at ( i, j ); }

      inline EstadoCel operator()( const Coord& C ) const { return at ( C ); }

      inline bool empty () const { return mapa.empty (); }

      inline bool origDestDefinidos () const { return celulaLivre ( orig ) && celulaLivre ( dest ); }

      bool coordValida ( const Coord& C ) const;

      bool celulaLivre ( const Coord& C ) const;

      bool movimentoValido ( const Coord& Orig, const Coord& Dest ) const;

      bool setOrigem ( const Coord& C );

      bool setDestino ( const Coord& C );

      void imprimir() const;

      double calculaCaminho ( int& NC, int& NA, int& NF );
};

#endif // _LABIRINTO_H_
