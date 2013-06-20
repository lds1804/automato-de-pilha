#include "automato2.h"
#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

void automato::insereestado(bool fim,int iden,bool ini) // adiciona um estado ao automato
{
    estado* pointer;
    pointer = new estado;  // cria novo estado
    pointer->setfinal(fim); // configura estado com os parametros passados
    pointer->setini(ini);
    pointer->setid(iden);
    nest++;
    estados[nest]=pointer;
    if(ini==true)  // se o boolenao ini passado for true configura o ponteiro de estado inicial do automato para o ponteiro do estado atual
    {
        estini=pointer;
    }



}

void automato::imprimeaut()   // imprime o automato
{

        for(int i=0;estados[i]!=NULL;i++) //imprime o identificador dos estados e seus atributos
    {



        cout << estados[i]->getid()<<" ";

      if(estados[i]->getfinal()==true)
    cout  << "Final ";
     else
        cout << "nao final ";

     if(estados[i]->getinicial()==true)
        cout << "Inicial"<<endl;
     else
        cout << "Nao Inicial"<< endl ;

    cout<<"Transita para submaquina "<<estados[i]->gettransicaosub()<<endl;

      for(int j=0;j<=alfab->getncar();j++)
      {cout <<" "<< estados[i]->gettransicao(j);}



        }



    for(int j=0;j<=alfab->getncar();j++) // imprime os membros do alfabeto do automato
    {
        cout << " "<<alfab->getchar(j)<<endl;

    }






}



automato::automato() //configura id e numero de estados e seta o vetor de estados com todos os valores NULL e cria um novo alfabeto
{


    nest=-1;
    id=-1;

    for(int i=0; i<1000; i++)
    {
        estados[i]=NULL;


    }

    estadoatual=NULL;
    estini=NULL;
    alfab=new alfabeto();




}

void automato::inseretransicao(int idorigem,int iddest, string caractere) // insere transicao dentro de um estado
{    estado* origem;
     int index=-1;


    for(int i=0; i<=nest; i++) // procura dentro do vetor de estados o estado que corresponde ao id de origem e atribui a origem este ponteiro
        {  if(idorigem==estados[i]->getid())
                origem=estados[i];
        }

    for(int i=0;i<=alfab->getncar();i++) // procura dentro do vetor de caracteres do alfabeto o indice em que o caractere atual esta contido
    { if(caractere==alfab->getchar(i))
       index=i;

    }

    origem->inseretransicao(iddest,index); // com o indice e o ponteiro de origem insere a transicao



}

void automato::inserealfabeto(string caractere) // insere caractere no alfabeto
{

    alfab->inserecaractere(caractere);

}

void automato::consomecadeia(string cadeia) // metodo nao utilizado no automato de pilha
{   string charatual;
    estini=estados[0];
    estadoatual=estados[0];
    int tam;
    tam=cadeia.size();
    bool transitou=true;
    cout<<"Cadeia: "<<cadeia<<endl;

    for(int i=0;i<tam && transitou==true;i++)
    {  charatual=cadeia[i];
       cout << "Estado atual "<<estadoatual->getid()+1<<" "<<"caracter atual "<< charatual;
       if(alfab->pertencealfabeto(charatual)==true)
       {    int indice=alfab->getindice(charatual);
            int indiceprox= estadoatual->gettransicao(indice);
            cout <<" transita para "<<indiceprox+1<<endl;
            if(indiceprox!=-1)
            estadoatual=estados[indiceprox];
            else transitou=false;


       }
       else
        {   int j=alfab->getncar();
            int indiceproximoest = estadoatual->gettransicao(j);
            cout <<" transita para "<<indiceproximoest+1<<endl;
            if(indiceproximoest!=-1)
            estadoatual=estados[indiceproximoest];
            else transitou=false;


        }


    }
    cout<<"Estado atual " << estadoatual->getid()+1;
    if (estadoatual->getfinal()==true)
    cout << " Estado Final"<<endl;
    else cout <<" Estado nao final"<<endl;

    if(transitou==true &&(estadoatual->getfinal()==true))
    cout <<"Cadeia aceita"<<endl;
    else
    cout <<"Cadeia nao aceita"<<endl<<endl<<endl;


}

void automato::inseretranspsub(int transicao, int estado) // insere transicao para submaquina dentro de um estado
{  estados[estado]->inseretransicaosub(transicao);



}

estado* automato::getestados(int indice) // retorna um ponteiro para estados com o valor do indice fornecido
{
    return estados[indice];
}

void automato::setestadoatual(estado* estadoatual2) // atualiza o esado atual do automato
{ estadoatual=estadoatual2;

}
void automato::setestadoinicial(estado* estadoinicial) // configura estado inicial
{ estini=estadoinicial;

}

bool automato::pertencealfabeto(string charatual) // passa para a classe alfabeto o caractere atual e esta verifica se pertence ou nao ao alfabeto
{
    return alfab->pertencealfabeto(charatual);
}

int automato::gettransicao(string caracteratual) // Verifica para onde o automato dado um caractere e utilizando o estado atual
{
    int indice=alfab->getindice(caracteratual); //pega o indice dentro do vetor de caracteres em que o caractere atual esta armazenado
    int transicao=estadoatual->gettransicao(indice);// transicao recebe o valor de retorno da funcao gettransicao utilizando o ponteiro de estado atual e o indice obtido acima
    return transicao;


}

int automato::gettransicaooutros()
{ int transicao=estadoatual->gettransicao(alfab->getncar()); // utiliza como indice o numero de caracteres para pegar a transicao para outros
    return transicao;



}

int automato::getestadoatual() // retorna o estado atual
{ return estadoatual->getid();

}

int automato::gettransicaosub() // retorna transicao para submaquina
{
    return estadoatual->gettransicaosub();
}

estado* automato::getestadoatualpoint() // retorna um ponteiro para o estado atual
{return estadoatual;

}

void automato::setid(int id2) // congigura o identificador da submaquina
{
    id=id2;
}
int automato::getid() // retorna o identificador da submaquian
{
    return id;
}

void automato::setretorno(int estado,int transicao) // configura o estado de retorno de submaquina
{   estados[estado]->settransicaoestadosub(transicao);

}
