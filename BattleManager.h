#pragma once

#include <BattlePkmn.h>
#include <queue>

class Move;

class BattleManager
{
private:
	BattlePkmn* bInfo1 = nullptr;
	BattlePkmn* bInfo2 = nullptr;

	std::queue<Move*> moves;

public:

	void SetCreature1(BattlePkmn* b1);
	void SetCreature2(BattlePkmn* b2);

	void SlowestMoveToRearOfQueue(int min_index);
	int SlowestPriority(int sorted_index);
	void SortMoveQueue();

	void Turn();
	void BeforeMoveStatusEffects(BattlePkmn* activeInfo);

	void StartTurnStatus();
	void EndOfTurnStatus();

};

