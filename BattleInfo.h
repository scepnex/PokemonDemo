#pragma once

//class will manage battle information for a pokemon creature
//volatile status effects, buffs/debuffs, move history


#include <vector>
#include <list>
#include <Status.h>
#include <StatModifiers.h>

class Move;

class BattleInfo
{
	Creature& parent_;

	Move* currentMove;
	std::list<Move*> creatureMoves;
	
	SolidStatus* statusEffect;
	std::vector<VolatileStatus*> volatileStatuses;

	StatModifiers statMods;

public:

	BattleInfo(Creature& parent) : parent_(parent) { currentMove = nullptr; statusEffect = nullptr; }

	void ApplyStatus(SolidStatus* effect);
	void ApplyVolatileStatus(VolatileStatus* effect);

	void SetCurrentMove(Move* move) { currentMove = move; }
	Move* GetCurrentMove() { return currentMove; }

	float getStat(Stats stat) { return float(parent_.getStat(stat)); }
	float getStatMod(Stats stat);

	std::string getName() { return parent_.getName(); }

	int priority();

	void Damage(int value, Types type = TYPE_NONE);
	void StatusEffectBeforeMove();
	void OnDamage(Creature& sender) {}
	void StatusEndOfTurn();
};

