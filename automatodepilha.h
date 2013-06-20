#ifndef AUTOMATODEPILHA_H_INCLUDED
#define AUTOMATODEPILHA_H_INCLUDED
#include "automato2.h"
#include "pilha.h"


class automatodepilha
{

private:
    automato* automatos[1000];
    int nautomatos;
    pilha* pilhadeestados;



public:
    automatodepilha();
    void inseretransub(int submaquina,int estadoatual,string caractere, int transicao);
    void inseresubmaquina(int idsubmaquina);
    void consomecadeia(string cadeia);
    int getnautomatos();
    void pushestsub(int estado,int submaquina);
    int popestado();
    int popsubmaquina();
    string popsimbolo();
    void inserealfabetosub(int submaq,string caracetere);
    void inseretransretorno(int submaq,int estado,int transicao);
    void imprimeautpilha();
    void insereestado(int submaquina,bool fim,int iden,bool ini);
    void inseretransparasub(int submaquina, int transicao,int estado);
    void consomecadeiadepilha(string cadeia);
    int gettransicaosub(automato* submaquina,string caracteratual);





};


#endif // PILHA_H_INCLUDED
