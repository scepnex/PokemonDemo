#pragma once

#include <BattleInfo.h>

class BattleManager
{
private:
	BattleInfo* bInfo1;
	BattleInfo* bInfo2;



public:

	void SetCreature1(BattleInfo* b1);
	void SetCreature2(BattleInfo* b2);



	void Turn();
	bool DeterminePriority();
	void CreatureTurn(BattleInfo* activeInfo, BattleInfo* targetInfo);
	void BeforeMoveStatusEffects(BattleInfo* activeInfo);
	bool TryAttack(BattleInfo* activeInfo, BattleInfo* targetInfo);
	void ApplyAttack(BattleInfo* activeInfo, BattleInfo* targetInfo);
	void EndOfTurnStatus();

};

