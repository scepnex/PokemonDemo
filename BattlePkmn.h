#pragma once

//class will manage battle information for a pokemon creature
//volatile status effects, buffs/debuffs, move history


#include <vector>
#include <list>
#include <Status.h>
#include <StatModifiers.h>

class Move;

class BattlePkmn
{
	Creature& parent_;

	Move* currentMove;
	std::vector<Move*> creatureMoves;
	
	SolidStatus* statusEffect;
	std::list<VolatileStatus*> volatileStatuses;

	StatModifiers statMods;

	std::list<Status*> effectOnTurnStart;
	std::list<Status*> effectBeforeMove;
	std::list<Status*> effectAfterMove;
	std::list<Status*> effectOnTurnEnd;
	std::list<Status*> effectOnHitPhase;

public:

	BattlePkmn(Creature& parent) : parent_(parent) { currentMove = nullptr; statusEffect = nullptr; }

	void AddMove(Move* moveToAdd) { creatureMoves.push_back(moveToAdd); }

	void SelectRandomMove();

	void ApplyStatus(SolidStatus* effect);
	void ApplyVolatileStatus(VolatileStatus* effect);

	void AddTurnStartEffect(Status* effect) { effectOnTurnStart.push_back(effect); }
	void RemoveTurnStartEffect(Status* effect) { effectOnTurnStart.remove(effect); }

	void AddBeforeMoveEffect(Status* effect) { effectBeforeMove.push_back(effect); }
	void RemoveBeforeMoveEffect(Status* effect) { effectBeforeMove.remove(effect); }

	void AddEndOfTurnEffect(Status* effect) { effectOnTurnEnd.push_back(effect); }
	void RemoveEndOfTurnEffect(Status* effect) { effectOnTurnEnd.remove(effect); }

	void AddOnHitEffect(Status* effect) { effectOnHitPhase.push_back(effect); }
	void RemoveOnHitEffect(Status* effect) { effectOnHitPhase.remove(effect); }

	void SetCurrentMove(Move* move) { currentMove = move; }
	Move* GetCurrentMove() { return currentMove; }

	float getStat(Stats stat) { return float(parent_.getStat(stat)); }
	float getStatMod(Stats stat);

	Types getType(int index);

	std::string getName() { return parent_.getName(); }

	int priority();

	void Damage(int value, Types type = TYPE_NONE);
	void OnDamage(BattlePkmn* sender) { StatusEffectsOnHitPhase(); }

	void StatusEffectsOnTurnStart();
	void StatusEffectsBeforeMove();
	void StatusEffectsEndOfTurn();
	void StatusEffectsOnHitPhase();
};

