#include <iostream>
#include <string>
#include "csapat.h"
#include "kezi.h"
#include "memtrace.h"

using std::string;

void Kezi::save(std::ostream& os) const {
    string n; int l;
    n=getNev(); l=getLetszam();
    os << "kezi" << '\t' << n << '\t' << l << '\t'
           << tamogatas << std::endl;
    }


void Kezi::kiir(){
    string n; int l;
    n=getNev(); l=getLetszam();
    std::cout<<"kezi "<<n<< " " <<l<< " " <<tamogatas<<std::endl;
    //Csapat::kiir();
}
