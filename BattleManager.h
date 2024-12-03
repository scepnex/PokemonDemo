#pragma once

#include <BattleInfo.h>
#include <queue>

class Move;

class BattleManager
{
private:
	BattleInfo* bInfo1;
	BattleInfo* bInfo2;

	std::queue<Move*> moves;

public:

	void SetCreature1(BattleInfo* b1);
	void SetCreature2(BattleInfo* b2);

	void SlowestMoveToRearOfQueue(int min_index);
	int SlowestPriority(int sorted_index);
	void SortMoveQueue();



	void Turn();
	bool DeterminePriority();
	void CreatureTurn(BattleInfo* activeInfo, BattleInfo* targetInfo);
	void BeforeMoveStatusEffects(BattleInfo* activeInfo);
	//bool TryAttack(BattleInfo* activeInfo, BattleInfo* targetInfo);
	//void ApplyAttack(BattleInfo* activeInfo, BattleInfo* targetInfo);
	void BeforeTurnStatus() {}
	void EndOfTurnStatus();

};

