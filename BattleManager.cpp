#include "BattleManager.h"
#include "Move.h"

using namespace std;

static float randomFloat()
{
	rand(); // we added a call to rand here because i did not feel like dealing with a better solution for c++ randomness
	return (float)(rand()) / (float)(RAND_MAX);
}

void BattleManager::SetCreature1(BattleInfo* b1)
{
	bInfo1 = b1;
}

void BattleManager::SetCreature2(BattleInfo* b2)
{
	bInfo2 = b2;
}

bool BattleManager::DeterminePriority()
{
	int priority1 = bInfo1->priority();
	int priority2 = bInfo2->priority();

	bool moveOrder = true; // true if p1 goes first, false if p2 goes first

	//Determine who moves first
	//based on move priority (quick attack, extremespeed, paralys
	if (priority1 < priority2)
	{
		moveOrder = false;
	}
	else if (priority1 == priority2)
	{
		//speed comparison
		if (bInfo1->getStat(SPEED) < bInfo2->getStat(SPEED))
		{
			moveOrder = false;
		}
		else if (bInfo1->getStat(SPEED) == bInfo2->getStat(SPEED))
		{
			//choose random pokemon to go first
			cout << "\n creatures are of equal speed, random first will be chosen (not implemented)\n";
		}
	}
	return moveOrder;
}
void BattleManager::BeforeMoveStatusEffects(BattleInfo* activeInfo)
{
	activeInfo->StatusEffectBeforeMove();
}

bool BattleManager::TryAttack(BattleInfo* activeInfo, BattleInfo* targetInfo)
{
	cout << activeInfo->getName() << " used " << activeInfo->GetCurrentMove()->getName() << ".\n";
	
	bool result = false;
	
	float moveAcc = activeInfo->GetCurrentMove()->getAccuracy();
	float modifierTotal = activeInfo->getStatMod(ACCURACY) * targetInfo->getStatMod(EVASION);

	float accuracyRoll = randomFloat() * 100.f;
	
	float modifierCalc = moveAcc * modifierTotal;
	result = accuracyRoll <= modifierCalc;

	cout << "    Accuracy roll: " << accuracyRoll << " <= " << modifierCalc << endl;

	return result;
}

void BattleManager::ApplyAttack(BattleInfo* activeInfo, BattleInfo* targetInfo)
{
	activeInfo->GetCurrentMove()->Execute(activeInfo, targetInfo);

	//cout << active->getName() << " attacked " << target->getName() << " with " << activeInfo->GetCurrentMove()->getName() << ".\n";
}

void BattleManager::EndOfTurnStatus()
{
	bInfo1->StatusEndOfTurn();
	bInfo2->StatusEndOfTurn();
}


void BattleManager::CreatureTurn(BattleInfo* activeInfo, BattleInfo* targetInfo)
{

	BeforeMoveStatusEffects(activeInfo);

	if (TryAttack(activeInfo, targetInfo))
	{
		cout << "    Success!\n";
		ApplyAttack(activeInfo, targetInfo);
	}
	else
	{
		cout << "    " << activeInfo->getName() << " missed!\n";
	}
}

void BattleManager::Turn()
{
	bool moveOrder = DeterminePriority();

	if (moveOrder)
	{
		//1 moves first
		//2 moves second

		CreatureTurn(bInfo1, bInfo2);
		CreatureTurn(bInfo2, bInfo1);
	}
	else
	{
		//2 moves first
		//1 moves second

		CreatureTurn(bInfo2, bInfo1);
		CreatureTurn(bInfo1, bInfo2);
	}

	EndOfTurnStatus();

}

