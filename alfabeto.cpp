#include "alfabeto.h"
#include <iostream>
#include <string>


void alfabeto::inserecaractere(string carac) // insere um caractere no alfabeto
{


    int flag=0; // flag que indica se um caractere ja pertence ao alfabeto
     ncarac++;

    for(int i=0;i<=ncarac;i++) // verifica se o caractere ja foi inserido no alfabeto
    { if(caracteres[i]==carac)
        {flag=1;}

    }

    if(flag==0)
    caracteres[ncarac]=carac;
}


alfabeto::alfabeto() // inicializa com 0 o alfabeto
{  ncarac=-1;

    for(int i=0;i<1000;i++)
    caracteres[i]="0";


}

int alfabeto::getncar() // retorna o numero de caracters do alfabeto -1
{ return ncarac;

}

string alfabeto::getchar(int i)  // retorna o valor do caractere presente no indice i do vetor de caracteres
{ return caracteres[i];

}

//int alfabeto::maiorcadeia(string cadeia)
//{
//
//
//
// return 0;
//}

bool alfabeto::pertencealfabeto(string caractere) // verifica se um caractere pertence ou nao ao alfabeto
    {   bool pertence=false;

        for(int i=0;i<ncarac;i++)
            {   if(caracteres[i]==caractere)
                    pertence=true;
            }
        return pertence;

    }
int alfabeto::getindice(string caractere)   // procura no alfabeto por um caractere e retorna o indice dentro do vetor de caracteres em que
    {  int indice;                          // este esta presente
        for(int i=0;i<ncarac;i++)
        { if(caracteres[i]==caractere)
             indice=i;

        }

       return indice;
    }
