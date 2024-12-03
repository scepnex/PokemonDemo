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
	void BeforeMoveStatusEffects(BattleInfo* activeInfo);

	void BeforeTurnStatus() {}
	void EndOfTurnStatus();

};

