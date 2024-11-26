#pragma once

#include <Creature.h>
#include <BattleInfo.h>

class BattleManager
{
private:
	Creature& combatant1; //in a single player context, this will be the player
	BattleInfo& bInfo1;

	Creature& combatant2; //in single player, this will be the Computer player
	BattleInfo& bInfo2;



public:
	void Turn();
	void DeterminePriority();
	void BeforeMoveStatusEffects();
	void TryAttack();
	void ApplyAttack();
	void EndOfTurnStatus();

};

