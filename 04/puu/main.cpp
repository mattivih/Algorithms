#include <iostream>
#include <string>
using namespace std;

//Binääripuun solmu.


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

    int* _arg1 = 0;
    int* _arg2 = 0;
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
    int audible = 1;
    int visible = 0;
    int on_flank = 0;
    int distance = 7;
    int distance_treshold = 10;

    // Apuarvot
    int true_val = 1;
    int false_val = 0;

    Equal n1("Is enemy visible?", &visible, &true_val);
    Equal n2("Is enemy visible?", &visible, &true_val);
    LessThan n3("Is enemy < 10m away?", &distance, &distance_treshold);
    Equal n4("Is enemy on flank?", &on_flank, &true_val);
    Action n5("CREEP");
    Action n6("ATTACK");
    Action n7("MOVE");
    Action n8("DO NOTHING");

    n1._left = &n3;     n1._right = &n2;
    n3._left = &n6;     n3._right = &n4;
    n4._left = &n7;     n4._right = &n6;
    n2._left = &n5;     n2._right = &n8;

    n1.evaluate();

    return 0;
}

