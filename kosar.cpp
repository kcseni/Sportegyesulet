#include <iostream>
#include <string>
#include "csapat.h"
#include "kosar.h"
#include "memtrace.h"

using std::string;

void Kosar::save(std::ostream& os) const {
    string n; int l;
    n=getNev(); l=getLetszam();
        os << "kosar" << '\t' << n << '\t' << l << '\t'
           << pompom << std::endl;
    }



void Kosar::kiir(){
    string n; int l;
    n=getNev(); l=getLetszam();
    std::cout<<"kosar "<<n<< " " <<l<< " " <<pompom<<std::endl;
    //Csapat::kiir();
}
