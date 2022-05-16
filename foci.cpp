#include <iostream>
#include <string>
#include "csapat.h"
#include "foci.h"
#include "memtrace.h"


using std::string;

void Foci::save(std::ostream& os) const {
    string n; int l;
    n=getNev() ; l=getLetszam();
    os << "foci" << '\t' << n << '\t' << l << '\t'
           << edzo1 << '\t' << edzo2 << std::endl;
}


void Foci::kiir(){
    string n; int l;
    n=getNev(); l=getLetszam();
    std::cout<<"foci "<< n <<" "<< l<< " "<<edzo1<< " "<<edzo2<<std::endl;

}
