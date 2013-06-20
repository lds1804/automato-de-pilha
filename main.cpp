#include <stdio.h>
#include <string>
#include "automato2.h"
#include <iostream>
#include "pilha.h"
#include "automatodepilha.h"


using namespace std;


int main()

{   string cadeia;

  automatodepilha aut;
  aut.inseresubmaquina(0);
  aut.inserealfabetosub(0,"a");
  aut.inserealfabetosub(0,",");
  aut.inserealfabetosub(0,"(");
  aut.inserealfabetosub(0,")");
  aut.inserealfabetosub(0,"[");
  aut.inserealfabetosub(0,"]");
  aut.inserealfabetosub(0,"{");
  aut.inserealfabetosub(0,"}");


  aut.insereestado(0,false,0,true);
  aut.insereestado(0,false,1,false);
  aut.insereestado(0,false,2,false);
  aut.insereestado(0,true,3,false);
  aut.insereestado(0,false,4,false);
  aut.insereestado(0,false,5,false);
  aut.insereestado(0,false,6,false);
  aut.insereestado(0,false,7,false);

  aut.inseretransub(0,0,"a",3);
  aut.inseretransub(0,0,"(",1);
  aut.inseretransub(0,0,"[",4);
  aut.inseretransub(0,0,"{",6);
  aut.inseretransub(0,2,")",3);
  aut.inseretransub(0,3,",",0);
  aut.inseretransub(0,5,"]",3);
  aut.inseretransub(0,7,"}",3);

  aut.inseretransparasub(0,0,1);  //testar a inserção da transicao de submaquina
  aut.inseretransparasub(0,0,4);
  aut.inseretransparasub(0,0,6);

  aut.inseretransretorno(0,1,2);
  aut.inseretransretorno(0,4,5);
  aut.inseretransretorno(0,6,7);

  //aut.consomecadeiadepilha("a");
  //aut.consomecadeiadepilha("(a)");
  //aut.consomecadeiadepilha("[a,a]");
  //aut.consomecadeiadepilha("a,a,a,a");
  //aut.consomecadeiadepilha("{a}");
  //aut.consomecadeiadepilha("(a),a,(a),[a],{a},a");
  //aut.consomecadeiadepilha("(((a))),[[a]],{{{{a}}}}");
  //aut.consomecadeiadepilha("{[((a),[a],{a})]}");
  //aut.consomecadeiadepilha("a,([a],{a}),[(a),{{a}}],{[(a),a],a},a");

 automatodepilha aut2;
 aut2.inseresubmaquina(0);
 aut2.inseresubmaquina(1);

aut2.inserealfabetosub(0,"i");
aut2.inserealfabetosub(0,"=");
aut2.inserealfabetosub(0,";");
aut2.inserealfabetosub(0,"n");
aut2.inserealfabetosub(0,"(");
aut2.inserealfabetosub(0,")");
aut2.inserealfabetosub(0,"+");
aut2.inserealfabetosub(0,"-");
aut2.inserealfabetosub(0,"*");
aut2.inserealfabetosub(0,"/");
aut2.inserealfabetosub(0,"e");


aut2.inserealfabetosub(1,"i");
aut2.inserealfabetosub(1,"=");
aut2.inserealfabetosub(1,";");
aut2.inserealfabetosub(1,"n");
aut2.inserealfabetosub(1,"(");
aut2.inserealfabetosub(1,")");
aut2.inserealfabetosub(1,"+");
aut2.inserealfabetosub(1,"-");
aut2.inserealfabetosub(1,"*");
aut2.inserealfabetosub(1,"/");
aut2.inserealfabetosub(1,"e");

aut2.insereestado(0,false,0,true);
aut2.insereestado(0,false,1,false);
aut2.insereestado(0,false,2,false);
aut2.insereestado(0,true,3,false);

  aut2.insereestado(1,false,0,true);
 aut2.insereestado(1,false,1,false);
 aut2.insereestado(1,false,2,false);
 aut2.insereestado(1,true,3,false);

 aut2.inseretransub(0,0,"i",1);
 aut2.inseretransub(0,1,"=",2);
 aut2.inseretransub(0,3,";",0);
 aut2.inseretransub(0,3,"e",3);

 aut2.inseretransparasub(0,1,2);

aut2.inseretransretorno(0,2,3);

 aut2.inseretransub(1,0,"n",3);
 aut2.inseretransub(1,0,"i",3);
 aut2.inseretransub(1,0,"(",1);
 aut2.inseretransub(1,2,")",3);
 aut2.inseretransub(1,3,"+",0);
 aut2.inseretransub(1,3,"-",0);
 aut2.inseretransub(1,3,"*",0);
 aut2.inseretransub(1,3,"/",0);


 aut2.inseretransparasub(1,1,1);
 aut2.inseretransretorno(1,1,2);


 aut2.consomecadeiadepilha("i=n+n;i=n+(i*(n))e");
aut2.consomecadeiadepilha("i=n;i=n+(i*(n*))e");
























    return 0;

}
