#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include <string>
#include "csapat.h"
#include <iostream>
#include <fstream>
using namespace std;

class CsapatLista{
    size_t darab;
    Csapat *csapatok[100];
    CsapatLista(const Csapat&);
    CsapatLista operator=(const Csapat&);

public:
    CsapatLista():darab(0) {}

    void ujcsapat(Csapat *uj);

    void listaz();

    void torol(string mit);

    void beolvas(string fajlnev);

    void mentes(string fajlnev);

    ~CsapatLista() {
        for(size_t i=0; i<darab; i++){
            delete csapatok[i];
        }
    }
};



#endif // LISTA_H_INCLUDED
