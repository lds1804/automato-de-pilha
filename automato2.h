#ifndef AUTOMATO2_H_INCLUDED
#define AUTOMATO2_H_INCLUDED
#include "estado.h"
#include "alfabeto.h"
#include <string>


class automato

{
private:
    int id;
    estado* estados[1000];
    estado* estini;
    alfabeto* alfab;
    estado* estadoatual;
    int nest;


public:
    automato();
    void insereestado(bool fim,int iden,bool ini);
    void inserealfabeto(string caractere);
    void setestini(bool ini);
    void setestadoatual(estado* estadoatual2);
    void setestadoinicial(estado* estadoinicial);
    void imprimeaut();
    void inseretransicao(int idorigem,int iddest, string caractere);
    void consomecadeia(string cadeia);
    void inseretranspsub(int transicao,int estado);
    estado* getestados(int indice);
    int gettransicao(string caracteratual);
    bool pertencealfabeto(string charatual);
    int gettransicaooutros();
    int gettransicaosub();
    int getestadoatual();
    estado* getestadoatualpoint();
    void setid(int id2);
    int getid();
    void setretorno(int estado,int transicao);









};




#endif // AUTOMATO2_H_INCLUDED
