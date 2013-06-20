#include "pilha.h"
#include <string>
#include <iostream>
#include <fstream>


void pilha::pushestsubmaquina(int submachine,int estado) // armazena nos vetores da pilha a submaquina e o estado de retorno da submaquina
{ ofstream myfile;
    myfile.open("saida.txt",ios::app);
    nestados++;
    estados[nestados]=estado;
    submaquinas[nestados]=submachine;
    //cout<<" Recebeu Submaquina: "<<submachine<<" Estado:"<<estado<<" Nestados:"<< nestados<<endl;
    myfile<<"Empilha "<<" Submaquina:"<<submaquinas[nestados]<< " Estado: "<<estados[nestados]<<endl;



}

int pilha::popsubmaquina() // retorna o topo da pilha da submaquina
{ int submaquina=-1;
     ofstream myfile;
    myfile.open("saida.txt",ios::app);
    if(nestados>=0)
    submaquina=submaquinas[nestados];
    myfile << "Desempilha submaquina: "<< submaquina<<endl;
    return submaquina;

}

int pilha::popestado() // retorna o topo da pilha de estados e decrementa numero de elementos na pilha, dado por nestados
{    ofstream myfile;
    myfile.open("saida.txt",ios::app);
    int estado=-1;
    if(nestados>=0)
        {estado=estados[nestados];
        nestados--;
        }
    myfile << "Desempilha estado: "<< estado<<endl;

    return estado;


}



pilha::pilha() // contrutor da pilha
{   nestados=-1;
    for(int i=0;i<1000;i++)
    { estados[i]=-1;
      submaquinas[i]=-1;

    }



}

int pilha::getnestados() // retorna numero de estados
{
    return nestados;
}
