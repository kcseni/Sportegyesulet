#include <string>
#include "csapat.h"
#include <iostream>
#include <fstream>
#include "lista.h"
#include "foci.h"
#include "kezi.h"
#include "kosar.h"
#include "memtrace.h"

using namespace std;

void CsapatLista::ujcsapat(Csapat *uj){
        if(darab<100){
            csapatok[darab] = uj;
            darab++;
        }
    }

void CsapatLista::listaz(){
        for(size_t i=0; i<darab; i++){
            csapatok[i]->kiir();
        }
    }

void CsapatLista::torol(string mit){
        for(size_t i=0; i<darab; i++){
            if(mit==csapatok[i]->getNev()){
                delete csapatok[i];
                darab-=1;
                for(size_t k=i; k<darab; k++){
                    csapatok[i]=csapatok[k+1];
                }
                cout<<mit<<" nevu csapat torolve.\n"<<endl;
                return;
            }
        }
        std::cout<<"Nincs ilyen nevu csapat.\n"<<std::endl;
    }

void CsapatLista::beolvas(string fajlnev){

        std::ifstream is;
        is.open(fajlnev.c_str());
        if(!is){
            std::cerr<<"Nincs ilyen fajl.\n";


        }
        std::string s;
        darab=0;

        while(!is.eof()){
                getline(is, s);
                darab++;
        }
        darab--;
        //cout<<darab<<endl;

        is.close();

        std::ifstream is2;
        is2.open(fajlnev.c_str());
        cout<<"A fajl megnyitasa sikeres."<<endl;


            string tipus[darab], nev, edzo1, edzo2; int letszam, pom, tamogatas;
            char tab;
            for(size_t i=0; i<darab; i++){
            is2>>tipus[i];
            if(tipus[i]=="foci"){
                is2.get(tab);
                getline(is2, nev, '\t');
                is2>>letszam;
                is2.get(tab);
                getline(is2, edzo1, '\t');
                getline(is2, edzo2, '\n');
                //cout<<tipus[i]<<nev<<letszam<<edzo1<<edzo2<<endl;

                csapatok[i]=new Foci(nev, letszam, edzo1, edzo2);
                //csapatok[i]->kiir();

            }
            else if(tipus[i]=="kosar"){
                is2.get(tab);
                getline(is2, nev, '\t');
                is2>>letszam;
                is2>>pom;
                //cout<<tipus[i]<<nev<<letszam<<pom<<endl;
                csapatok[i]=new Kosar(nev, letszam, pom);
                //csapatok[i]->kiir();
            }
            else if(tipus[i]=="kezi"){
                is2.get(tab);
                getline(is2, nev, '\t');
                is2>>letszam;
                is2>>tamogatas;
                //cout<<tipus[i]<<nev<<letszam<<tamogatas<<endl;

                csapatok[i]=new Kezi(nev, letszam, tamogatas);
                //csapatok[i]->kiir();

            }
        }
        is2.close();

    }


void CsapatLista::mentes(string fajlnev){
        std::ofstream os;
        os.open(fajlnev.c_str());
        for(size_t i=0; i<darab; i++){
            (csapatok[i]->save(os));
        }
        os.close();

    }

