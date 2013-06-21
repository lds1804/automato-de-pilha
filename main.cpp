#include <stdio.h>
#include <string>
#include "automato2.h"
#include <iostream>
#include "pilha.h"
#include "automatodepilha.h"
#include <fstream>
#include <sstream>

using namespace std;


int main()

{
    string line;
    automatodepilha aut;
    int estado,inicial,fim;
    bool fimb,inicialb;



    fstream file;
    file.open("entrada.txt",ios::in);

    while(file.eof()==false)
    {
        int numerodesubamquinas;
        getline(file,line);
        stringstream ss(line);
        ss>>numerodesubamquinas;
        cout<<numerodesubamquinas<<endl;

        for(int i=0; i<numerodesubamquinas; i++)
        {
            aut.inseresubmaquina(i);


        }


        getline(file,line);
        cout<<line<<endl;
        int nelalfabeto;
        stringstream s2(line);
        s2>>nelalfabeto;
        for(int j=0; j<nelalfabeto; j++)
        {
            getline(file,line);
            for(int g=0; g<numerodesubamquinas; g++)
                aut.inserealfabetosub(g,line);


        }

        getline(file,line);
        int nestados;
        stringstream s3(line);
        s3>>nestados;



        for(int t=0; t<nestados; t++)
        {
            getline(file,line);
            int subi,esti,fimi,idi,inii;
            string sub=line.substr(0,1);
            string fim=line.substr(2,1);
            string id=line.substr(4,1);
            string ini=line.substr(6,1);

            stringstream s4(sub);
            s4>>subi;
            stringstream s5(id);
            s5>>idi;
            stringstream s6(fim);
            s6>>fimi;
            stringstream s8(ini);
            s8>>inii;
            bool f,i;
            if(fimi==1)
                f=true;
            else f=false;

            if(inii==1)
                i=true;
            else i=false;

            //cout<<"subi;"<<subi<<" f:"<<f<<" idi:"<<idi<<" i:"<<i<<endl;
            aut.insereestado(subi,f,idi,i);

        }
        int ntransicoes;
        getline(file,line);
        stringstream s9(line);
        s9>> ntransicoes;

        for(int h=0; h<ntransicoes; h++)
        {
            getline(file,line);
            int subi2,orii,desti;
            string sub=line.substr(0,1);
            string ori=line.substr(2,1);
            string ch=line.substr(4,1);
            string dest=line.substr(6,1);

            stringstream s10(sub);
            s10>>subi2;
            stringstream s11(ori);
            s11>>orii;
            stringstream s12(dest);
            s12>>desti;

            cout<<"submaquina:"<<subi2<<" origem:"<<orii<<" caracter:"<<ch<<" destino:"<<desti<<endl;

            aut.inseretransub(subi2,orii,ch,desti);

            getchar();





        }

        getline(file,line);
        stringstream s13(line);
        int ntransicoespsub;
        s13>>ntransicoespsub;
        cout<<"ntransiccoespsub:"<<ntransicoespsub<<endl;
        getchar();
        for(int e=0; e<ntransicoespsub; e++)
        {
            int sub3i,est1i,subci;
            getline(file,line);
            string sub3=line.substr(0,1);
            stringstream s14(sub3);
            s14>>sub3i;
            cout<<"Submaquina:"<<sub3i<<endl;
            getchar();
            string est3=line.substr(2,1);
            stringstream s15(est3);
            s15>>est1i;
            getchar();
            string subc=line.substr(4,1);
            stringstream s16(subc);
            s16>>subci;
            getchar();

            cout<<"submaquina:" <<sub3i<<"estado:"<<est1i<<"submaquinai:"<<subci<<endl;
            getchar();
            aut.inseretransparasub(sub3i,est1i,subci);
            getchar();


        }

        getline(file,line);
        stringstream s17(line);
        int ntransicoesrsub;
        s17>>ntransicoesrsub;
        cout<<"ntransicoesrsub"<<ntransicoesrsub<<endl;
        getchar();

        for(int l=0; l<ntransicoesrsub; l++)
        {
            int sub4i,est4i,estri;
            getline(file,line);
            string sub4=line.substr(0,1);
            string est4=line.substr(2,1);
            string estr=line.substr(4,1);
            stringstream s18(sub4);
            s18>>sub4i;
            stringstream s19(est4);
            s19>>est4i;
            stringstream s20(estr);
            s20>>estri;
            cout<<"sub:"<<sub4i<<" estado:"<<est4i<<" estretorno:"<<estri<<endl;
            getchar();
            aut.inseretransretorno(sub4i,est4i,estri);

        }

        getline(file,line);
        stringstream s21(line);
        int ncadeias;
        s21>>ncadeias;
        cout<<"ncadeias"<<ncadeias<<endl;
        getchar();

        for(int w=0; w<ncadeias; w++)
        {
            getline(file,line);
            aut.consomecadeiadepilha(line);

        }







    }




//    automatodepilha aut;
//    aut.inseresubmaquina(0);
//    aut.inserealfabetosub(0,"a");
//    aut.inserealfabetosub(0,",");
//    aut.inserealfabetosub(0,"(");
//    aut.inserealfabetosub(0,")");
//    aut.inserealfabetosub(0,"[");
//    aut.inserealfabetosub(0,"]");
//    aut.inserealfabetosub(0,"{");
//    aut.inserealfabetosub(0,"}");
//
//
//    aut.insereestado(0,false,0,true);
//    aut.insereestado(0,false,1,false);
//    aut.insereestado(0,false,2,false);
//    aut.insereestado(0,true,3,false);
//    aut.insereestado(0,false,4,false);
//    aut.insereestado(0,false,5,false);
//    aut.insereestado(0,false,6,false);
//    aut.insereestado(0,false,7,false);
//
//    aut.inseretransub(0,0,"a",3);
//    aut.inseretransub(0,0,"(",1);
//    aut.inseretransub(0,0,"[",4);
//    aut.inseretransub(0,0,"{",6);
//    aut.inseretransub(0,2,")",3);
//    aut.inseretransub(0,3,",",0);
//    aut.inseretransub(0,5,"]",3);
//    aut.inseretransub(0,7,"}",3);
//
//    aut.inseretransparasub(0,0,1);  //testar a inserção da transicao de submaquina
//    aut.inseretransparasub(0,0,4);
//    aut.inseretransparasub(0,0,6);
//
//    aut.inseretransretorno(0,1,2);
//    aut.inseretransretorno(0,4,5);
//    aut.inseretransretorno(0,6,7);

    //aut.consomecadeiadepilha("a");
    //aut.consomecadeiadepilha("(a)");
    //aut.consomecadeiadepilha("[a,a]");
    //aut.consomecadeiadepilha("a,a,a,a");
    //aut.consomecadeiadepilha("{a}");
    //aut.consomecadeiadepilha("(a),a,(a),[a],{a},a");
    //aut.consomecadeiadepilha("(((a))),[[a]],{{{{a}}}}");
    //aut.consomecadeiadepilha("{[((a),[a],{a})]}");
    //aut.consomecadeiadepilha("a,([a],{a}),[(a),{{a}}],{[(a),a],a},a");

//    automatodepilha aut2;
//    aut2.inseresubmaquina(0);
//    aut2.inseresubmaquina(1);
//
//    aut2.inserealfabetosub(0,"i");
//    aut2.inserealfabetosub(0,"=");
//    aut2.inserealfabetosub(0,";");
//    aut2.inserealfabetosub(0,"n");
//    aut2.inserealfabetosub(0,"(");
//    aut2.inserealfabetosub(0,")");
//    aut2.inserealfabetosub(0,"+");
//    aut2.inserealfabetosub(0,"-");
//    aut2.inserealfabetosub(0,"*");
//    aut2.inserealfabetosub(0,"/");
//    aut2.inserealfabetosub(0,"e");
//
//
//    aut2.inserealfabetosub(1,"i");
//    aut2.inserealfabetosub(1,"=");
//    aut2.inserealfabetosub(1,";");
//    aut2.inserealfabetosub(1,"n");
//    aut2.inserealfabetosub(1,"(");
//    aut2.inserealfabetosub(1,")");
//    aut2.inserealfabetosub(1,"+");
//    aut2.inserealfabetosub(1,"-");
//    aut2.inserealfabetosub(1,"*");
//    aut2.inserealfabetosub(1,"/");
//    aut2.inserealfabetosub(1,"e");
//
//    aut2.insereestado(0,false,0,true);
//    aut2.insereestado(0,false,1,false);
//    aut2.insereestado(0,false,2,false);
//    aut2.insereestado(0,true,3,false);
//
//    aut2.insereestado(1,false,0,true);
//    aut2.insereestado(1,false,1,false);
//    aut2.insereestado(1,false,2,false);
//    aut2.insereestado(1,true,3,false);
//
//    aut2.inseretransub(0,0,"i",1);
//    aut2.inseretransub(0,1,"=",2);
//    aut2.inseretransub(0,3,";",0);
//    aut2.inseretransub(0,3,"e",3);
//
//    aut2.inseretransparasub(0,1,2);
//
//    aut2.inseretransretorno(0,2,3);
//
//    aut2.inseretransub(1,0,"n",3);
//    aut2.inseretransub(1,0,"i",3);
//    aut2.inseretransub(1,0,"(",1);
//    aut2.inseretransub(1,2,")",3);
//    aut2.inseretransub(1,3,"+",0);
//    aut2.inseretransub(1,3,"-",0);
//    aut2.inseretransub(1,3,"*",0);
//    aut2.inseretransub(1,3,"/",0);
//
//
//    aut2.inseretransparasub(1,1,1);
//    aut2.inseretransretorno(1,1,2);
//
//
//    aut2.consomecadeiadepilha("i=n+n;i=n+(i*(n))e");
//    aut2.consomecadeiadepilha("i=n;i=n+(i*(n*))e");
























    return 0;

}
