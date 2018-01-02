#include <math.h>
#include "ai.h"


void AI::set_parameters(double attack_range, double defense_range)
{
	_attack_range = attack_range;
	_defense_range = defense_range;
}


double AI::test_AI()
{
	double x = _attack_range + 1;
	double y = _defense_range + 2;

	return exp(-(x*x + y*y));
}
