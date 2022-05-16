#ifndef KEZI_H_INCLUDED
#define KEZI_H_INCLUDED

#include "csapat.h"
#include <iostream>
#include <string>
using std::string;

class Kezi: public Csapat{
    int tamogatas;
public:
    Kezi(string n, int l, int tamogatas): Csapat(n, l), tamogatas(tamogatas) {}
    void save(std::ostream& os) const;
    void load(std::istream& is);
    void kiir();

};

#endif // KEZI_H_INCLUDED
