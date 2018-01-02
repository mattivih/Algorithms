#include <iostream>
#include <ai.h>
using namespace std;

// Tehtävä:
// Optimoi tekoälyn parametrit käyttäen Hill Climbing -algoritmia.
// Ts. etsi sellaiset attack_range ja defense_range -parametrien
// arvot, joilla .test_AI() palauttaa mahdollisimman suuren arvon.

double HillClimb(double val1, double val2, double step, AI ai)
{
	double _val1 = val1, arr[2] = { 0, 0 };

	while(1)
	{
		double val_up = _val1 + step;
		double val_down = _val1 - step;
		ai.set_parameters(val_up, val2);
		double up = ai.test_AI();
		ai.set_parameters(val_down, val2);
		double down = ai.test_AI();
		if (up > down)
		{
			_val1 = val_up;
			arr[0] = up;
		}
		else if (up < down)
		{
			_val1 = val_down;
			arr[0] = down;
		}
		if (arr[0] > arr[1])
			arr[1] = arr[0];
		else if (arr[0] < arr[1])
		{
			_val1 = arr[1];
			break;
		}
		std::cout << "value " << arr[1] << endl;
	}
	return _val1;
}


int main()
{
	AI my_ai;
	double atk = 0, def = 0, step = 0.1, opt = 0;

	// Haetaan algoritmilla paras attack-arvo.
	double datk = HillClimb(atk, def, step, my_ai);
	double ddef = HillClimb(def, datk, step, my_ai);
		
	my_ai.set_parameters(datk, ddef);
	opt = my_ai.test_AI();
	cout << "AI optimal quality " << opt << endl;

	return 0;
}
