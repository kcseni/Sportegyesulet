#ifndef KOSAR_H_INCLUDED
#define KOSAR_H_INCLUDED

#include <iostream>
#include <string>
#include "csapat.h"
using std::string;

class Kosar: public Csapat{
    int pompom;
public:
    Kosar(string n, int l, int pompom): Csapat(n, l), pompom(pompom) {}
    void save(std::ostream& os) const;
    void load(std::istream& is);
    void kiir();

};


#endif // KOSAR_H_INCLUDED
