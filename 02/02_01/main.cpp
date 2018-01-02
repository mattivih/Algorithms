/*
#include <iostream>
#include <map>
using namespace std;

int main() {
    int _rounds = 0, _max_rounds = 0, _points = 0, _counter = 0;
    string _history, _input, _comp_guess;

    map<string, int> _4gram;
    _4gram["llll"] = 0;
    _4gram["lllr"] = 0;
    _4gram["llrl"] = 0;
    _4gram["llrr"] = 0;
    _4gram["lrll"] = 0;
    _4gram["lrlr"] = 0;
    _4gram["lrrl"] = 0;
    _4gram["lrrr"] = 0;
    _4gram["rlll"] = 0;
    _4gram["rllr"] = 0;
    _4gram["rlrl"] = 0;
    _4gram["rlrr"] = 0;
    _4gram["rrll"] = 0;
    _4gram["rrlr"] = 0;
    _4gram["rrrl"] = 0;
    _4gram["rrrr"] = 0;

    cout << "How many rounds?" << endl;
    cin >> _rounds;10
    _max_rounds = _rounds;

    while(_rounds > 0){

        do{
            cout << "l(eft) or r(ight)" << endl;
            cin >> _input;
        }
        while(_input != "l" && _input != "r");

        _history += _input;
        
        if(_counter < 4){
            srand (time(NULL));
            int _rand = rand() % 2 + 1;
            if(_rand == 1)
                _comp_guess = "l";
            if(_rand == 2)
                _comp_guess = "r";
        }

        else{
            string _left_opt = _history.substr(_history.length()-3) + "l";
            int _left_frek = _4gram[_left_opt];
            
            string _right_opt = _history.substr(_history.length()-3) + "r";
            int _right_frek = _4gram[_right_opt];

            if(_left_frek > _right_frek)
                _comp_guess = "l";
            else if(_left_frek < _right_frek)
                _comp_guess = "r";
            else{
                srand (time(NULL));
                int _rand = rand() % 2 + 1;
                if(_rand == 1)
                    _comp_guess = "l";
                if(_rand == 2)
                    _comp_guess = "r";
            }
            string _add_to_4gram = _history.substr(_history.length()-3) + _input;
            _4gram[_add_to_4gram]++;
        }
        if(_input != _comp_guess){
            cout << "I guessed wrong." << endl;
            _points++;
        }
        else
            cout << "I guessed correct." << endl;

        _counter++;
        _rounds--;

    }
    if(_points >= _max_rounds/2)
        cout << "Score: " << _points << ". You win." << endl;
    else if(_points < _max_rounds/2)
        cout << "Score: " << _points << ". You lose." << endl;

    return 0;
}
*/
#include <iostream>
#include <map>
using namespace std;

int main() {
    int _rounds = 0, _max_rounds = 0, _points = 0, _counter = 0;
    string _history, _input, _comp_guess;

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
                _comp_guess = "0";
            if(_rand == 1)
                _comp_guess = "1";
            if(_rand == 2)
                _comp_guess = "2";
        }

        else{
            string _rock_opt = _history.substr(_history.length()-3) + "0";
            int _rock_frek = _4gram[_rock_opt];

            string _paper_opt = _history.substr(_history.length()-3) + "1";
            int _paper_frek = _4gram[_paper_opt];

            string _scissors_opt = _history.substr(_history.length()-3) + "2";
            int _scissors_frek = _4gram[_scissors_opt];

            if(_rock_frek > _paper_frek && _rock_frek > _scissors_frek)
                _comp_guess = "0";
            else if(_paper_frek > _rock_frek && _paper_frek > _scissors_frek)
                _comp_guess = "1";
            else if(_scissors_frek > _rock_frek && _scissors_frek > _paper_frek)
                _comp_guess = "2";
            else{
                cout << "random: " << endl;
                srand (time(NULL));
                int _rand = rand() % 3;
                if(_rand == 0)
                    _comp_guess = "0";
                if(_rand == 1)
                    _comp_guess = "1";
                if(_rand == 2)
                    _comp_guess = "2";
            }
            string _add_to_4gram = _history.substr(_history.length()-3) + _input;
            _4gram.insert(std::pair<string, int>(_add_to_4gram, _4gram[_add_to_4gram]++));
            //Ngram.insert (key, ngram [key]++)

        }
        if(_input != _comp_guess){
            cout << "I guessed wrong." << endl;
            _points++;
        }
        else
            cout << "I guessed correct." << endl;

        _counter++;
        _rounds--;

    }
    if(_points >= _max_rounds/2)
        cout << "Score: " << _points << ". You win." << endl;
    else if(_points < _max_rounds/2)
        cout << "Score: " << _points << ". You lose." << endl;

    return 0;
}