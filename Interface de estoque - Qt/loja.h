#ifndef _LOJA_H_
#define _LOJA_H_

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Produto {
    private:
        string nome;
        unsigned preco;
    public:
        inline Produto ( const string &N = "", unsigned P = 0 ): nome ( N ), preco ( P ) {}

        inline string getNome () const { return nome; }
        inline double getPreco() const { return preco / 100.0; }

        bool ler ( istream &input );
        void salvar ( ostream &output ) const;
        void digitar ();
        inline void imprimir () const { salvar ( cout ); }
};

inline istream& operator>> ( istream &input, Produto &P ) { P.digitar (); return input; }
inline ostream& operator<< ( ostream &output, const Produto &P ) { P.salvar ( output ); return output; }

class Livro: public Produto {
    private:
        string autor;
    public:
        inline Livro ( const string &N = "", unsigned P = 0, const string &A = "" ): Produto ( N, P ), autor ( A ) {}

        inline string getAutor () const { return autor; }

        bool ler ( istream &input );
        void salvar ( ostream &output ) const;
        void digitar ();
        inline void imprimir () const { return salvar ( cout ); }
};

inline istream& operator>> ( istream &input, Livro &L ) { L.digitar (); return input; }
inline ostream& operator<< ( ostream &output, const Livro &L ) { L.salvar ( output ); return output; }

class CD: public Produto {
    private:
        unsigned nfaixas;
    public:
        inline CD ( const string &N = "", unsigned P = 0, unsigned NF = 0 ): Produto ( N, P ), nfaixas ( NF ) {}

        inline unsigned getNumFaixas () const { return nfaixas; }

        bool ler ( istream &input );
        void salvar ( ostream &output ) const;
        void digitar ();
        inline void imprimir () const { salvar ( cout ); }
};

inline istream& operator>> ( istream &input, CD &C ) { C.digitar (); return input; }
inline ostream& operator<< ( ostream &output, const CD &C ) { C.salvar ( output ); return output; }

class DVD: public Produto {
    private:
        unsigned duracao;
    public:
        inline DVD(const string &N = "", unsigned P = 0, unsigned D = 0 ): Produto ( N, P ), duracao ( D ) {}

        inline unsigned getDuracao () const { return duracao; }

        bool ler ( istream &input );
        void salvar ( ostream &output ) const;
        void digitar ();
        inline void imprimir () const { salvar ( cout ); }
};

inline istream& operator>> ( istream &input, DVD &D) { D.digitar (); return input; }
inline ostream& operator<< ( ostream &output, const DVD &D ) { D.salvar ( output ); return output; }

class Loja {
    private:
        vector <Livro> LL;
        vector <CD> LC;
        vector <DVD> LD;
    public:
    inline Loja (): LL (), LC(), LD() {}

    /// Funcoes de consulta
    inline unsigned getNumLivro () const { return LL.size(); }
    inline unsigned getNumCD () const { return LC.size(); }
    inline unsigned getNumDVD () const { return LD.size(); }
    Livro getLivro ( unsigned id ) const;
    CD getCD ( unsigned id ) const;
    DVD getDVD ( unsigned id ) const;

    inline void incluirLivro(const Livro &X ) { LL.push_back ( X ); }
    bool excluirLivro ( unsigned id );
    inline void incluirCD ( const CD &X ) { LC.push_back ( X ); }
    bool excluirCD ( unsigned id );
    inline void incluirDVD ( const DVD &X ) { LD.push_back ( X ); }
    bool excluirDVD ( unsigned id );

    /// Funcoes de entrada/saida
    bool ler ( const string &arq );
    bool salvar ( const string &arq ) const;
    void imprimir () const;
};
#endif // _LOJA_H_
