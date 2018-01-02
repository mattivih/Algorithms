#include <iostream>
#include "solmu.h"

int main() {

    Solmu A("a"), B("b"), C("c"), D("d"), E("e"), F("f"), G("g");
    A._naapurit.push_back(&B);
    A._naapurit.push_back(&C);
    A._naapurit.push_back(&D);
    A._etaisyys.push_back(1.3);
    A._etaisyys.push_back(1.6);
    A._etaisyys.push_back(3.3);
    B._naapurit.push_back(&E);
    B._naapurit.push_back(&F);
    B._etaisyys.push_back(1.5);
    B._etaisyys.push_back(1.9);
    C._naapurit.push_back(&D);
    C._etaisyys.push_back(1.3);
    F._naapurit.push_back(&G);
    F._etaisyys.push_back(1.4);

    // Alustukset
    Solmu* alku = &A;
    Solmu* loppu = &G;
    SolmuLista avoimet;
    SolmuLista suljetut;
    avoimet.push_back(alku);
    alku->_lyhin_tunnettu_reitti = 0;

    // Dijkstran algoritmi
    while(1)
    {
        // 1. Valitaan käsiteltävä solmu s
        Solmu* s = avoimet.poista_pienin();
        if(!s)
            break;

        // 2. Käydään läpi s;n naapurit
        for (unsigned i = 0; i < s->_naapurit.size(); ++i)
        {
            Solmu* n = s->_naapurit[i];
            double s_n = s->_etaisyys[i];
            if(s->_lyhin_tunnettu_reitti + s_n < n->_lyhin_tunnettu_reitti)
            {
                // 3. Ollaan löydetty aikaisempaa lyhyempi reitti naapuriin n. Päivitetään sen tiedot.
                n->_lyhin_tunnettu_reitti = s->_lyhin_tunnettu_reitti + s_n;
                n->_yhteys = s;
                avoimet.lisaa(n);
            }
        }

        suljetut.lisaa(s);
        if(s == loppu)
            break;
    }

    // Tulostetaan reitti
    Solmu* s = loppu;
    while(s)
    {
        std::cout << s->_nimi << "\n";
        s = s->_yhteys;
    }
    std::cout << loppu->_lyhin_tunnettu_reitti << "\n";

    return 0;
}