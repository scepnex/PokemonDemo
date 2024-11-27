#pragma once

//class will manage battle information for a pokemon creature
//volatile status effects, buffs/debuffs, move history


#include <vector>
#include <Status.h>
#include <BattleMove.h>
#include <StatModifiers.h>

class BattleInfo
{
	SolidStatus* statusEffect;

	std::vector<VolatileStatus*> volatileStatuses;

	BattleMove* currentMove;

	StatModifiers statMods;

public:

	void StatusEffectBeforeMove();
	void StatusEndOfTurn();

	void SetCurrentMove(BattleMove* move) { currentMove = move; }
	BattleMove* GetCurrentMove() { return currentMove; }

	float getStatMod(Stats stat);

	int priority();
};

