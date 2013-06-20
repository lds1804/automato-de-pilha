#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED
#include <string>
#include <stdio.h>


using namespace std;

class pilha
{
private:
    int estados[1000];
    int submaquinas[1000];
    string simbolos[1000];
    int nestados;

public:
    void pushestsubmaquina( int submachine,int estado);
    int popestado();
    int popsubmaquina();
    pilha();
    int getnestados();




};


#endif // PILHA_H_INCLUDED
