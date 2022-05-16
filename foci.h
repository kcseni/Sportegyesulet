#ifndef FOCI_H_INCLUDED
#define FOCI_H_INCLUDED

#include <iostream>
#include <string>
#include "csapat.h"
using std::string;

class Foci: public Csapat{
    string edzo1;
    string edzo2;
public:
    Foci(string n, int l, string edzo1, string edzo2):Csapat(n, l), edzo1(edzo1), edzo2(edzo2) {}
    void save(std::ostream& os) const;
    void kiir();

};


#endif // FOCI_H_INCLUDED
