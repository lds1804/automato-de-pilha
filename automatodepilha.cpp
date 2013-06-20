#include "automatodepilha.h"
#include <string>
#include <iostream>
#include <fstream>



using namespace std;

automatodepilha::automatodepilha() // contrutor do automato de pilha
{
    nautomatos=-1;
    pilhadeestados= new pilha;

}

void automatodepilha::inseresubmaquina(int idsubmaquina) // adiciona submaquina ao automato
{
   // cout<< "insere submaquina "<<idsubmaquina<<endl;
    automato* pointaut=new automato; // cria um novo automato
    automatos[idsubmaquina]=pointaut;// coloca o automato criado com o id fornecido dentro do vetor de submaquinas do automato de pilha
    pointaut->setid(idsubmaquina);// Configura id da submaquina

}

void automatodepilha::inseretransretorno(int submaq,int estado,int transicao) // insere transicao de retorno de subamaquina dentro de um estado de dada submaquina
{
   automato* submaquina;
   submaquina=automatos[submaq];
   submaquina->setretorno(estado,transicao);


}




void automatodepilha::consomecadeia(string cadeia)
{



}

int automatodepilha::getnautomatos() // retorna o numero de automatos -1
{
    return nautomatos;


}

void automatodepilha::pushestsub(int estado,int submaquina) //empilha estado e submaquina na pilhadeestados
{
    pilhadeestados->pushestsubmaquina(submaquina,estado);

}

int automatodepilha::popestado() // desempilha estado da pilha de estados
{
    return pilhadeestados->popestado();


}


int automatodepilha::popsubmaquina() // desempilha submaquina da pilhadeestados
{
    return pilhadeestados->popsubmaquina();

}




void automatodepilha::inserealfabetosub(int submaq,string caractere) // insere caractere dentro do alfabeto das submaquinas
{   //cout<< "Inserealfabetosub Submaq "<<submaq<<" Caractere "<<caractere<<endl;
    automato* submaquina;
    submaquina=automatos[submaq];
    submaquina->inserealfabeto(caractere);



}

void automatodepilha::imprimeautpilha() // imprime automatos 0 e 1
{ automatos[0]->imprimeaut();
  //automatos[1]->imprimeaut();


}

void automatodepilha::insereestado(int submaquina,bool fim,int iden,bool ini) //insere estado em uma submaquina
{   automato* submachine;
    submachine=automatos[submaquina];
    submachine->insereestado(fim,iden,ini);

}

void automatodepilha::inseretransparasub(int submaquina, int transicao,int estado) //insere transicao para submaquina dentro de um estado
{   automato* sub;
    sub=automatos[submaquina];
    sub->inseretranspsub(transicao,estado);

}


void automatodepilha::consomecadeiadepilha(string cadeia) // consome uma cadeia
{
    ofstream myfile;
    myfile.open("saida.txt",ios::app);

    automato* submaquinaatual;
    submaquinaatual=automatos[0]; // configura submaquina atual
    string charatual;
    submaquinaatual->setestadoatual(submaquinaatual->getestados(0));// configura estado atual da submaquina atual
    submaquinaatual->setestadoatual(submaquinaatual->getestados(0));
    int tam;
    tam=cadeia.size();
    bool transitou=true;
    myfile<<"Cadeia "<<cadeia<<endl;
    string caracteratual;
    bool consumiucaracte=false;
    bool empilhousubmaquina;
    bool desempilhousubmaquina;

    for(int i=0;i<tam&&transitou==true;i++)
    { caracteratual=cadeia[i];// pega caractere
     consumiucaracte=false;
     empilhousubmaquina=false;
     desempilhousubmaquina=false;


      if(submaquinaatual->pertencealfabeto(caracteratual)==true) // verifica se caractere pertence ao alfabeto
       {

           int transicao= submaquinaatual->gettransicao(caracteratual); // pega transicao utilizando a funcao gettransicao com o caractere atual e a submaquina atual, nao eh necessario passar o estado atual pois este é acessado utilizando a submaquina atual
            if(transicao!=-1)//verifica se a transiçao é válida
            myfile << "Submaquina atual "<<submaquinaatual->getid()<<" Estado atual: "<< submaquinaatual->getestadoatual()<<" Caractere atual: "<<caracteratual<<" Transita para: "<<transicao<<endl;

            if(transicao!=-1)//verifica se a transiçao é válida
                {submaquinaatual->setestadoatual(submaquinaatual->getestados(transicao));//com o indice transicao por meio da funcao getestados pega um ponteiro para estado e utiliza este ponteiro para atualizar o estado atual
                 consumiucaracte=true;

                }


       }

     if(submaquinaatual->pertencealfabeto(caracteratual)==false) // verifica se o caractere nao pertence ao alfabeto
            {   //cout <<"Nao pertence ao alfabeto"<<endl;
                int transicao= submaquinaatual->gettransicaooutros();
                if(transicao!=-1)
                myfile << "Submaquina atual "<<submaquinaatual->getid()<<" Estado atual: "<< submaquinaatual->getestadoatual()<<" Caractere atual: "<<caracteratual<<" Transita para: "<<transicao<<endl;

                if(transicao!=-1) // verifica se a transicao é valida
              { submaquinaatual->setestadoatual(submaquinaatual->getestados(transicao)); //com o indice transicao por meio da funcao getestados pega um ponteiro para estado e utiliza este ponteiro para atualizar o estado atual
                consumiucaracte=true;
              }



            }


     if(submaquinaatual->gettransicaosub()!=-1&&consumiucaracte==false) // verifica se nao consumiu caracteres nos dois primeiros if's e se existe transição valida para uma submaquina
            { //cout <<"Transicao de submaquina" <<endl;

                int transicao= submaquinaatual->gettransicaosub(); // pega a transicao de submaquina do estado corrente
              //cout << "Submaquina atual "<<submaquinaatual->getid()<<" Estado atual: "<< submaquinaatual->getestadoatual()<<" Caractere atual: "<<caracteratual<<" Transita para submaquina : "<<transicao<<endl;

              if(transicao!=-1) // vefica se a transição é valida
              { myfile <<"Transita para submaquina:"<<transicao<<" Submaquina atual:" << submaquinaatual->getid()<<" Estado de retorno de submaquina: "<<submaquinaatual->getestadoatualpoint()->gettransicaoestadosub()<<endl;
                pushestsub(submaquinaatual->getestadoatualpoint()->gettransicaoestadosub(),submaquinaatual->getid());//empilha o id da submaquina atual e o estado de retorno da submaquina. obtem por meio da submaquina atual e do estado atual e utilizando a funcao gettransicaoestadosub o estado de retorno de submaquina
                submaquinaatual=automatos[transicao];// atualiza submaquina atual
                submaquinaatual->setestadoatual(submaquinaatual->getestados(0));// atualiza estado atual
                empilhousubmaquina=true;
                i--;
              }
             // cout << "Submaquina atual apos atualizacao"<<submaquinaatual->getid()<<" Estado atual: "<< submaquinaatual->getestadoatual()<<" Caractere atual: "<<caracteratual<<" Transita para submaquina : "<<transicao<<endl;
             //getchar();

            }
    if(pilhadeestados->getnestados()!=-1&&submaquinaatual->getestadoatualpoint()->getfinal()==true&&consumiucaracte==false)//verifica se nao consumiu caracteres,nem empilhou caracteres e verifica se a pilha esta cheia, entao desempilha estado e submaquina e atualiza o automato
            {

                myfile <<"Sem transicoes"<<endl;



                submaquinaatual=automatos[pilhadeestados->popsubmaquina()];//desempilha submaquina e atualiza submaquina atual

                submaquinaatual->setestadoatual(submaquinaatual->getestados(pilhadeestados->popestado()));//obtem um ponteiro para estado por meio do identificador do estado obtido no desempilhamento e da funcao getestados() e assim atualiza estado atual da submaquinaatual

                i--;
                desempilhousubmaquina=true;


            }
    if(empilhousubmaquina==false&&desempilhousubmaquina==false&&consumiucaracte==false) //caso um caractere nao tenho sido consumido, nem houve empilhamento nem desempilhamento de submaquina e estado, entao nao houve transiçoes e pode-se terminar o automato
       {
           myfile <<"Nao transitou com caracetere"<< caracteratual<<endl;
           transitou=false;

       }




    }


    if(transitou==true && submaquinaatual->getestadoatualpoint()->getfinal()==true&&pilhadeestados->getnestados()==-1)//testa se a cadeia foi aceita para isto verifica o booleano true que deve ser true, verifica o numero de elementos da pilha que deve ser -1 e verifica se o estado final é de aceitação
    myfile <<"Cadeia aceita"<<endl<<endl;
    else
    myfile <<"Cadeia nao aceita"<<endl;


    if(transitou==false) //imprime o motivo da nao aceitaçao
        myfile << "Automato nao transitou com um dos caracteres"<<endl<<endl;

    else if(pilhadeestados->getnestados()!=-1)
        myfile << "Pilha Cheia"<<endl<<endl;

    else
        if(submaquinaatual->getestadoatualpoint()->getfinal()==false)
     myfile<<"Estado final nao e de aceitacao"<<endl<<endl;







}


void automatodepilha::inseretransub(int submaquina,int estadoatual,string caractere, int transicao) // insere uma transicao de uma submaquina
{  automato* submachine;
   submachine=automatos[submaquina];
   submachine->inseretransicao(estadoatual,transicao,caractere);



}


