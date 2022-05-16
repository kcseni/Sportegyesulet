#ifndef CSAPAT_H_INCLUDED
#define CSAPAT_H_INCLUDED

#include <iostream>
#include <string>
using std::string;


class Csapat{
    string nev;
    int letszam;
public:
    Csapat(string nev, int letszam):nev(nev), letszam(letszam) {}
    void setNev(string nv){
        this->nev=nv;
    }
    void setLetszam(int letsz){
        this->letszam=letsz;
    }
    string getNev() const{
        return this->nev;
    }
    int getLetszam() const{
        return this->letszam;
    }
    virtual void save(std::ostream& os) const = 0;
    virtual void kiir()=0;
    virtual ~Csapat() {};

};

#endif // CSAPAT_H_INCLUDED
