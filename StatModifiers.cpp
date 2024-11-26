#include "StatModifiers.h"
#include <iostream>
using namespace std;

void StatModifiers::debugDisplayBuffs()
{
	cout << "\nCurrent Stat Modifiers:\n";
	if (statBuffs[ATTACK] != 0) cout << "Attack: " << statBuffs[ATTACK] << " levels, boosting x" << getStatMod(ATTACK) << endl;
	if (statBuffs[DEFENSE] != 0) cout << "Defense: " << statBuffs[DEFENSE] << " levels, boosting x" << getStatMod(DEFENSE) << endl;
	if (statBuffs[SPATK] != 0) cout << "SpAtk: " << statBuffs[SPATK] << " levels, boosting x" << getStatMod(SPATK) << endl;
	if (statBuffs[SPDEF] != 0) cout << "SpDef: " << statBuffs[SPDEF] << " levels, boosting x" << getStatMod(SPDEF) << endl;
	if (statBuffs[SPEED] != 0) cout << "Speed: " << statBuffs[SPEED] << " levels, boosting x" << getStatMod(SPEED) << endl;
}

float StatModifiers::getStatMod(Stats stat)
{
	float numerator = 2.f;
	float denominator = 2.f;
	float result = 0.f;

	if (statBuffs[stat] >= 0)
	{
		numerator = numerator + static_cast<float>(statBuffs[stat]); // positive sta boosts are added to the numerator
	}
	else
	{
		denominator = denominator - static_cast<float>(statBuffs[stat]); // negative stat boosts are added to the denominator
	}

	result = numerator / denominator;

	return result;
}