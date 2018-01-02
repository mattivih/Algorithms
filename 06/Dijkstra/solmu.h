#pragma once
#include <algorithm>
#include <list>
#include <string>
#include <vector>
#include <limits>

class Solmu
{
public:
    Solmu(const char* nimi) : _nimi(nimi) {}

    std::string _nimi;
    double _lyhin_tunnettu_reitti =
            std::numeric_limits<double>::max();
    Solmu* _yhteys = 0;
    std::vector<Solmu*> _naapurit;
    std::vector<double> _etaisyys;
};


class SolmuLista : public std::list < Solmu* >
{
public:
    Solmu* poista_pienin()
    {
        double pienin_etaisyys =
                std::numeric_limits<double>::max();
        Solmu* paluuarvo = 0;

        for (Solmu* s : *this)
        {
            if (s->_lyhin_tunnettu_reitti < pienin_etaisyys)
            {
                pienin_etaisyys = s->_lyhin_tunnettu_reitti;
                paluuarvo = s;
            }
        }

        remove(paluuarvo);
        return paluuarvo;
    }


    void lisaa(Solmu* s)
    {
        if (find(begin(), end(), s) == end())
        {
            push_back(s);
        }
    }

};
