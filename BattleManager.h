#pragma once

#include <Creature.h>
#include <BattleInfo.h>

class BattleManager
{
private:
	Creature* combatant1; //in a single player context, this will be the player
	BattleInfo* bInfo1;

	Creature* combatant2; //in single player, this will be the Computer player
	BattleInfo* bInfo2;

public:

	void SetCreature1(Creature* p1, BattleInfo* b1);
	void SetCreature2(Creature* p2, BattleInfo* b2);

	void Turn();
	bool DeterminePriority();
	void CreatureTurn(Creature* active, BattleInfo* activeInfo, Creature* target, BattleInfo* targetInfo);
	void BeforeMoveStatusEffects(BattleInfo* activeInfo);
	bool TryAttack(Creature* target, BattleInfo* targetInfo);
	void ApplyAttack(Creature* active, BattleInfo* activeInfo, Creature* target, BattleInfo* targetInfo);
	void EndOfTurnStatus();

};

