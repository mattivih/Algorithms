#include <iostream>
#include <map>
#include "bot_interface.h"
using namespace std;

class My_Bot : public Bot
{
public:
    virtual std::string get_name()
    {
        return "Make Trump-Rock Great Again";
    }

    virtual int get_throw(int round)
    {
        int opp_prev = opp_throw[round-1];
        int own_prev = own_throw[round-1];

        if (round == 0) {
            return ROCK;
        }
        int _rounds = 0, _max_rounds = 0, _points = 0, _counter = 0;
        string _history, _input;

        map<string, int> _4gram;

        cout << "How many rounds?" << endl;
        cin >> _rounds;
        _max_rounds = _rounds;

        while(_rounds > 0){

            do{
                cout << "0(ROCK), 1(PAPER) or 2(SCISSORS): " << endl;
                cin >> _input;
            }
            while(_input != "0" && _input != "1" && _input != "2");

            _history += _input;

            if(_counter < 4){
                srand (time(NULL));
                int _rand = rand() % 3;
                if(_rand == 0)
                    return ROCK;
                if(_rand == 1)
                    return PAPER;
                if(_rand == 2)
                    return SCISSORS;
            }

            else{
                string _rock_opt = _history.substr(_history.length()-3) + "0";
                int _rock_frek = _4gram[_rock_opt];

                string _paper_opt = _history.substr(_history.length()-3) + "1";
                int _paper_frek = _4gram[_paper_opt];

                string _scissors_opt = _history.substr(_history.length()-3) + "2";
                int _scissors_frek = _4gram[_scissors_opt];

                if(_rock_frek > _paper_frek && _rock_frek > _scissors_frek)
                    return ROCK;
                else if(_paper_frek > _rock_frek && _paper_frek > _scissors_frek)
                    return PAPER;
                else if(_scissors_frek > _rock_frek && _scissors_frek > _paper_frek)
                    return SCISSORS;
                else{
                    cout << "random: " << endl;
                    srand (time(NULL));
                    int _rand = rand() % 3;
                    if(_rand == 0)
                        return ROCK;
                    if(_rand == 1)
                        return PAPER;
                    if(_rand == 2)
                        return SCISSORS;
                }
                string _add_to_4gram = _history.substr(_history.length()-3) + _input;
                _4gram.insert(std::pair<string, int>(_add_to_4gram, _4gram[_add_to_4gram]++));
            }
    }
};

