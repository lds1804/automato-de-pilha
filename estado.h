#ifndef ESTADO_H_INCLUDED
#define ESTADO_H_INCLUDED
#include <string>


class estado
{

private:
    bool finalest;
    bool iniest;
    int transicoes[1000];
    int transicaomaquina;
    int transicaoestadosub;
    int id;
    int ntrans;

public:
    estado();
    void setfinal(bool fim);
    void setini(bool ini);
    void setid(int id2);
    bool getfinal();
    int getid();
    bool getinicial();
    void inseretransicao(int destino, int indice);
    void inseretransicaosub(int submaquina);
    int gettransicao(int i);
    int getntrans();
    int gettransicaosub();
    int gettransicaoestadosub();
    void settransicaoestadosub(int transi);




};


#endif // ESTADO_H_INCLUDED
