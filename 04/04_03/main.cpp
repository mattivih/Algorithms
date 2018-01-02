#include <iostream>
#include <string>
using namespace std;

// Binääripuun solmu.

class Node
{
public:
    Node(const string& data) : _data(data) {}

    string _data;
    Node* _left = nullptr;
    Node* _right = nullptr;

    virtual void evaluate() = 0;
};

class Action : public  Node
{
public:
    Action(const string& data) : Node(data){}

    void evaluate()
    {
        // "Execute" action.
        cout << _data << "\n";
    }
};

class Decision : public Node
{
public:
    Decision(const string& data, int* arg1, int* arg2) : Node(data), _arg1(arg1), _arg2(arg2) {}

    int* _arg1;
    int* _arg2;
};

class LessThan : public Decision
{
public:
    LessThan(const string& data, int* arg1, int* arg2) : Decision(data, arg1, arg2) {}

    void evaluate()
    {
        if(*_arg1 < *_arg2)
            _left->evaluate();
        else
            _right->evaluate();
    }
};

class Equal : public Decision
{
public:
    Equal(const string& data, int* arg1, int* arg2) : Decision(data, arg1, arg2) {}

    void evaluate()
    {
        if(*_arg1 == *_arg2)
            _left->evaluate();
        else
            _right->evaluate();
    }
};

int main()
{
    // Pelimaailman "data"
    int visible = 0;
    int friendly = 1;
    int support = 1;
    int ammo = 10;
    int ammo_treshold = 10;

    // Apuarvot
    int true_val = 1;

    Equal A("Is the shooter visible?", &visible, &true_val);
    Equal B("Is the shooter friendly?", &friendly, &true_val);
    Action C("FIND TARGET");
    LessThan D("Do you have less than 10 ammo left?", &ammo, &ammo_treshold);
    Action E("RUN");
    Action F("ATTACK");
    Equal G("Do you have support available?", &support, &true_val);
    Action H("SEARCH SOURCE");
    Action I("FIND SANCTUARY");

    A._left = &B;       A._right = &G;
    B._left = &C;       B._right = &D;
    D._left = &E;       D._right = &F;
    G._left = &H;       G._right = &I;

    A.evaluate();

    return 0;
}