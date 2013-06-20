#ifndef ALFABETO_H_INCLUDED
#define ALFABETO_H_INCLUDED
#include <string>

using namespace std;

class alfabeto

{
private:
    string caracteres[1000];
    int ncarac;


public:
    void inserecaractere(string carac);
    alfabeto();
    int getncar();
    string getchar(int i);
//    int maiorcadeia(string cadeia);
    bool pertencealfabeto(string caractere);
    int getindice(string caractere);



};



#endif // ALFABETO_H_INCLUDED
