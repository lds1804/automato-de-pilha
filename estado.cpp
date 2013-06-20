#include "estado.h"
#include <iostream>
#include <string>

using namespace std;

estado::estado()//inicialaiza identificação,transicoes e transicaoestadosub com -1
{ this->id=-1;

  for(int i=0;i<1000;i++)
   {transicoes[i]=-1;
   }

   transicaomaquina=-1;
   transicaoestadosub=-1;
}
void estado::setfinal(bool fim) // configura o booleano que indica se o estado é ou nao final
{ this->finalest=fim;


}



void estado::setini(bool ini)// configura o booleano que indica se o estado é ou nao inicial
{ this->iniest=ini;


}

void estado::setid(int id2)// configura a identificação do estado
{


this->id=id2;

}

int estado::getid()// retorna a identificacao do estado
{

return this->id;

}

bool estado::getinicial() // retorna o valor do booleano inicial
{

return this->iniest;

}

bool estado::getfinal()// retorna o valor do booleano final
{

return finalest;

}

void estado::inseretransicao(int destino,int indice)// Por meio de um indice e um valor de transicao insere um valor no vetor de transiçoes
{  transicoes[indice]=destino;

}

int estado::gettransicao(int i) // por meio de um indice retorna um valor no vetor de transiçoes do estado
{
    return transicoes[i];
}

int estado::getntrans() // retorna o numero de transiçoes ntrans
{   return ntrans;
}

void estado::inseretransicaosub(int transicao) // insere a transicao do  estado para uma submaquina
{  transicaomaquina=transicao;

}

int estado::gettransicaosub() // retorna a submaquina para qual este estado transita
{
    return transicaomaquina;
}
int estado::gettransicaoestadosub() // retorna o estado de retorno quando a submaquina é desempilhada
{ return transicaoestadosub;


}
void estado::settransicaoestadosub(int transi) // configura o estado de retorno de submaquina
{ transicaoestadosub=transi;

}
