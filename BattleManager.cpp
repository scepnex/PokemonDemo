#include "BattleManager.h"
#include "Move.h"

using namespace std;

void BattleManager::SetCreature1(BattleInfo* b1)
{
	bInfo1 = b1;
}

void BattleManager::SetCreature2(BattleInfo* b2)
{
	bInfo2 = b2;
}

void BattleManager::BeforeMoveStatusEffects(BattleInfo* activeInfo)
{
	activeInfo->StatusEffectsBeforeMove();
}

void BattleManager::EndOfTurnStatus()
{
	bInfo1->StatusEndOfTurn();
	bInfo2->StatusEndOfTurn();
}

int BattleManager::SlowestPriority(int sorted_index)
{
	int min_index = -1;
	Move* slowestMove = nullptr;
	int n = int(moves.size());
	for (int i = 0; i < n; i++)
	{
		Move* curr = moves.front();
		moves.pop();

		if (slowestMove == nullptr)
		{
			min_index = i;
			slowestMove = curr;
		}

		else
		{
			int currPriority = curr->movePriority();
			int slowestPriority = slowestMove->movePriority();
			if (currPriority == slowestPriority && i <= sorted_index)
			{
				//Speed breaks tie between same priority moves
				int currSpeed = curr->speedPriority();
				int slowestSpeed = slowestMove->speedPriority();
				if (currSpeed == slowestSpeed)
				{
					//move priority and speed priority are equal, so choose random move to go last
					float coinFlip = UsefulFunctions::randomFloat();

					cout << "move priority decided randomly: " << coinFlip << endl;

					if (coinFlip <= 0.5f)
					{
						min_index = i;
						slowestMove = curr;
					}

				}
				else if (currSpeed < slowestSpeed)
				{
					min_index = i;
					slowestMove = curr;
				}
			}
			else if (currPriority < slowestPriority && i <= sorted_index)
			{
				min_index = i;
				slowestMove = curr;
			}
		}

		moves.push(curr);
	}
	return min_index;
}

void BattleManager::SlowestMoveToRearOfQueue(int min_index)
{
	Move* slowest;
	int n = moves.size();

	for (int i = 0; i < n; i++)
	{
		Move* curr = moves.front();
		moves.pop();
		if (i != min_index)
		{
			moves.push(curr);
		}
		else
		{
			slowest = curr;
		}
	}
	moves.push(slowest);
}

void BattleManager::SortMoveQueue()
{
	for (int i = 0; i < moves.size(); i++)
	{
		int min_index = SlowestPriority(moves.size() - i);
		SlowestMoveToRearOfQueue(min_index);
	}
}

void BattleManager::Turn()
{
	BeforeTurnStatus();

	//bool moveOrder = DeterminePriority();

	//1 vs 1 Move target hack solution for now
	bInfo1->GetCurrentMove()->SetTarget(bInfo2);
	bInfo2->GetCurrentMove()->SetTarget(bInfo1);

	// add moves to queue
	moves.push(bInfo1->GetCurrentMove());
	moves.push(bInfo2->GetCurrentMove());

	//sort queue of moves
	SortMoveQueue();

	//process queue in order
	while (moves.empty() == false)
	{
		moves.front()->Execute();
		moves.pop();
	}

	EndOfTurnStatus();

}

