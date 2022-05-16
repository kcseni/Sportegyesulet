#include <iostream>
#include <string>
#include "foci.h"
#include "kosar.h"
#include "kezi.h"
#include <fstream>
#include <iomanip>
#include "csapat.h"
#include "lista.h"
#include "memtrace.h"


using namespace std;

void test1(){
    CsapatLista lista;
    cout<<"Uj csapat felvetele teszt\n"<<endl;
    cout<<"Milyen fajta csapatot szeretne felvenni?\n"<<"1. foci\n"<<"2. kezilabda\n"<<"3. kosarlabda\n"<<"Adja meg a sportag szamat!\n"<<endl;
    int n, letszam, tamogatas, pom; string nev, edzo1, edzo2, tmp;
    cin>>n;
    switch(n){
        case 1:
            cout<<"Adja meg a csapat nevet!\n"<<endl;
            getline(cin,tmp,'\n');
            getline(cin,nev);
            cout<<"Adja meg a csapat letszamat!\n"<<endl;
            cin>>letszam;
            cout<<"Adja meg a csapat egyik edzojenek nevet!\n"<<endl;
            getline(cin,tmp,'\n');
            getline(cin,edzo1);
            cout<<"Adja meg a csapat masik edzojenek nevet!\n"<<endl;
            getline(cin,edzo2, '\n');
            lista.ujcsapat(new Foci(nev, letszam, edzo1, edzo2)); break;
        case 2:
            cout<<"Adja meg a csapat nevet!\n"<<endl;
            getline(cin,tmp,'\n');
            getline(cin,nev);
            cout<<"Adja meg a csapat letszamat!\n"<<endl;
            cin>>letszam;
            cout<<"Adja meg a csapat evenkenti tamogatasanak osszeget!\n"<<endl;
            cin>>tamogatas;
            lista.ujcsapat(new Kezi(nev, letszam, tamogatas)); lista.listaz(); break;
        case 3:
            cout<<"Adja meg a csapat nevet!\n"<<endl;
            getline(cin,tmp,'\n');
            getline(cin,nev);
            cout<<"Adja meg a csapat letszamat!\n"<<endl;
            cin>>letszam;
            cout<<"Adja meg a csapatnak szurkolo pompomcsapat letszamat!\n"<<endl;
            cin>>pom;
            lista.ujcsapat(new Kosar(nev, letszam, pom)); break;
        default: cout<<"Nincs ilyen valasztasi lehetoseg.\n"<<endl;

    }
}

    void test2(){
        CsapatLista lista;
        cout<<"Az adatbazis kilistazasanak tesztje. A csapatok az adataikkal egyutt most megjelennek.\n"<<endl;
        lista.ujcsapat(new Foci("Prok", 11, "Kis Attila", "Nagy Anita")); //letrehozunk 3 csapatot, hogy legyen mit kilistazni.
        lista.ujcsapat(new Kezi("Tenyeresek", 20, 500000));
        lista.ujcsapat(new Kosar("Team", 17, 10));
        lista.listaz();

    }

    void test3(){
        CsapatLista lista;
        cout<<"Az adatbazis egy rekordjanak torlese teszt.\n"<<endl;
        lista.ujcsapat(new Foci("Prok", 11, "Kis Attila", "Nagy Anita")); //letrehozunk 3 csapatot, amelyikbol majd az egyiket kitoroljuk.
        lista.ujcsapat(new Kezi("Tenyeresek", 20, 500000));
        lista.ujcsapat(new Kosar("Team", 17, 10));
        cout<<"Most ezek a csapatok vannak:\n"<<endl;
        lista.listaz();
        cout<<"Melyik csapatot szeretne torolni?\n"<<"1. Prok\n"<<"2. Tenyeresek\n"<<"3. Team\n"<<"Adja meg a valasztott csapat sorszamat!\n"<<endl;
        int szam;
        cin>>szam;
        switch(szam){
        case 1:
            lista.torol("Prok");
            lista.listaz();
            cout<<"Prok csapat torolve.\n"<<endl;
            break;
        case 2:
            lista.torol("Tenyeresek");
            lista.listaz();
            cout<<"Tenyeresek csapat torolve.\n"<<endl; break;
        case 3:
            lista.torol("Team");
            lista.listaz();
            cout<<"Team csapat torolve.\n"<<endl; break;
        default: cout<<"Nincs ilyen valasztasi lehetoseg.\n"<<endl;
        }

    }

    void test4(){
        CsapatLista lista;
        cout<<"Fajlba mentes tesztje.\n"<<endl;
        lista.ujcsapat(new Kosar("Manok", 21, 9)); //letrehozunk egy csapatot, hogy legyen mit fajlba menteni.
        cout<<"Milyen neven akarja elmenteni az adatbazist?(fajl.txt format kell megadnia)\n"<<endl;
        string fajlnev;
        cin>>fajlnev;
        lista.mentes(fajlnev); //A program letrehozta a megfelelo mappaba a fajlt (vagy felulirta ha mar letezett).

    }

    void test5(){
        CsapatLista lista;
        cout<<"Fajlbol olvasas tesztje.\n"<<endl;
        cout<<"Adja meg a beolvasando fajl nevet!(fajl.txt formaban)\n"<<endl;
        string fajlnev;
        cin>>fajlnev;
        lista.beolvas(fajlnev);
        cout<<"A beolvasas sikeres volt. A csapatok az adataikkal most megjelennek."<<endl;
        lista.listaz();
    }

    void test6(){
        CsapatLista lista;
        cout<<"Program kiprobalasa teszt."<<endl;
        cout<<"Szeretne probafajlt beolvasni?(igen/nem)"<<endl;
        string valasz;
        cin>>valasz;
        if(valasz=="igen"){
            cout<<"Adja meg a probafajl nevet!(fajl.txt formaban)"<<endl;
            string fajlnev;
            cin>>fajlnev;
            lista.beolvas(fajlnev);
        }
        int szam;
        string nev;
        do{
            cout<< "\n1. Uj csapat felvetele\n"<<
                    "2. Csapat torlese\n"<<
                    "3. Adatbazis kilistazasa\n"<<
                    "4. Kilepes es mentes\n"<<
                    "Adja meg a valasztott menupont sorszamat!\n"<<endl;
            cin>>szam;
            switch(szam){
                case 1: {cout<<"Milyen fajta csapatot szeretne felvenni?\n"<<"1. foci\n"<<"2. kezilabda\n"<<"3. kosarlabda\n"<<"Adja meg a sportag szamat!\n"<<endl;
                        int n, letszam, tamogatas, pom; string nev, edzo1, edzo2, tmp;
                        cin>>n;
                        switch(n){
                            case 1:
                                cout<<"Adja meg a csapat nevet!\n"<<endl;
                                getline(cin,tmp,'\n');
                                getline(cin,nev);
                                cout<<"Adja meg a csapat letszamat!\n"<<endl;
                                cin>>letszam;
                                cout<<"Adja meg a csapat egyik edzojenek nevet!\n"<<endl;
                                getline(cin,tmp,'\n');
                                getline(cin,edzo1);
                                cout<<"Adja meg a csapat masik edzojenek nevet!\n"<<endl;
                                getline(cin,edzo2, '\n');
                                lista.ujcsapat(new Foci(nev, letszam, edzo1, edzo2)); break;
                            case 2:
                                cout<<"Adja meg a csapat nevet!\n"<<endl;
                                getline(cin,tmp,'\n');
                                getline(cin,nev);
                                cout<<"Adja meg a csapat letszamat!\n"<<endl;
                                cin>>letszam;
                                cout<<"Adja meg a csapat evenkenti tamogatasanak osszeget!\n"<<endl;
                                cin>>tamogatas;
                                lista.ujcsapat(new Kezi(nev, letszam, tamogatas)); break;
                            case 3:
                                cout<<"Adja meg a csapat nevet!\n"<<endl;
                                getline(cin,tmp,'\n');
                                getline(cin,nev);
                                cout<<"Adja meg a csapat letszamat!\n"<<endl;
                                cin>>letszam;
                                cout<<"Adja meg a csapatnak szurkolo pompomcsapat letszamat!\n"<<endl;
                                cin>>pom;
                                lista.ujcsapat(new Kosar(nev, letszam, pom)); break;
                            default: cout<<"Nincs ilyen valasztasi lehetoseg.\n"<<endl;

                            } break;}
                case 2: cout<<"Most ezek a csapatok vannak:\n"<<endl;
                        lista.listaz();
                        cout<<"Melyik csapatot szeretne torolni? Adja meg a nevet!\n"<<endl;
                        cin>>nev;
                        lista.torol(nev);

                        break;
                case 3: lista.listaz(); break;
                case 4: { cout<<"Milyen neven akarja elmenteni az adatbazist?(fajl.txt format kell megadnia)\n"<<endl;
                        string fajl;
                        cin>>fajl;
                        lista.mentes(fajl); break;}
                default: cout<<"Nincs ilyen menupont."<<endl; break;
            }


        }while(szam!=4);


    }





int main()
{
    CsapatLista lista;
    cout<<"Valasszon az alabbi tesztesetek kozul!\n"<<"1. Uj csapat felvetele teszt\n"<<"2. Csapatok kilistazasa teszt\n"<<"3. Csapat torlese teszt\n"<<"4. Mentes fajlba teszt\n"<<"5. Fajlbol olvasas teszt\n"<<"6. Program kiprobalasa teszt.\n"<<"Adja meg a valasztott teszteset sorszamat!\n"<<endl;
    int szam;
    cin>>szam;
    switch(szam){
        case 1: test1(); break;
        case 2: test2(); break;
        case 3: test3(); break;
        case 4: test4(); break;
        case 5: test5(); break;
        case 6: test6(); break;
        default: cout<<"Nincs ilyen valasztasi lehetoseg.\n"; break;
    }

    return 0;
}
