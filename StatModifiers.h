#pragma once
#include <Creature.h>


class StatModifiers
{
private:
	int maxAmtBuffs = 6;
	int statBuffs[NUM_BASESTATS] = { 0, 0, 0, 0, 0, 0 };

public:
	void applyBuff(Stats stat, int levels)
	{ 
		statBuffs[stat] += levels;
		if (statBuffs[stat] > maxAmtBuffs)
		{
			statBuffs[stat] = maxAmtBuffs;
		}
	}
	void setBuff(Stats stat, int value) { statBuffs[stat] = value; }

	void increaseByOneLevel(Stats stat) { applyBuff(stat, 1); }
	void increaseByTwoLevels(Stats stat) { applyBuff(stat, 2); }

	void decreaseByOneLevel(Stats stat) { applyBuff(stat, -1); }
	void decreaseByTwoLevels(Stats stat) { applyBuff(stat, -2); }

	void maximumBuff(Stats stat) { setBuff(stat, maxAmtBuffs); }
	void minimumBuff(Stats stat) { setBuff(stat, -maxAmtBuffs); }

	float getStatMod(Stats stat);


	void debugDisplayBuffs();
};

