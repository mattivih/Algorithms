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

        virtual int get_throw(int round) {
            int opp_prev = opp_throw[round - 1];
            int own_prev = own_throw[round - 1];

            int _n = 3, _counter = 0;
            string _history, _input;

            map<string, int> _Ngram;

            if (opp_prev == 0)
                _history += "0";
            else if (opp_prev == 1)
                _history += "1";
            else if (opp_prev == 2)
                _history += "2";

            if (round < _n)
                return ROCK;
            else{
                if (_counter < _n) {
                    srand(time(NULL));
                    int _rand = rand() % 3;
                    if (_rand == 0)
                        return ROCK;
                    else if (_rand == 1)
                        return PAPER;
                    else if (_rand == 2)
                        return SCISSORS;

                } else {
                    string _rock_opt = _history.substr(_history.length() - _n) + "0";
                    int _rock_frek = _Ngram[_rock_opt];

                    string _paper_opt = _history.substr(_history.length() - _n) + "1";
                    int _paper_frek = _Ngram[_paper_opt];

                    string _scissors_opt = _history.substr(_history.length() - _n) + "2";
                    int _scissors_frek = _Ngram[_scissors_opt];

                    if (_rock_frek > _paper_frek && _rock_frek > _scissors_frek)
                        return ROCK;
                    else if (_paper_frek > _rock_frek && _paper_frek > _scissors_frek)
                        return PAPER;
                    else if (_scissors_frek > _rock_frek && _scissors_frek > _paper_frek)
                        return SCISSORS;
                    else {
                        cout << "random: " << endl;
                        srand(time(NULL));
                        int _rand = rand() % 3;
                        if (_rand == 0)
                            return ROCK;
                        if (_rand == 1)
                            return PAPER;
                        if (_rand == 2)
                            return SCISSORS;
                    }
                    string _key = _history.substr(_history.length() - _n) + _input;
                    _Ngram.insert(std::pair<string, int>(_key, _Ngram[_key]++));
                }
            }
        }
};
