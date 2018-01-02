#pragma once

class AI
{
public:

	// Set parameters that guide AI's decisions.
	void set_parameters(double attack_range, double defense_range);

	// Test AI. Returns score that reflects AI's strenght,
	// the bigger the better.
	double test_AI();

private:

	double _attack_range = 0;
	double _defense_range = 0;
};
