#include "BattleManager.h"

void BattleManager::SetCreature1(Creature* p1, BattleInfo* b1)
{
	combatant1 = p1;
	bInfo1 = b1;

	if (combatant1 != nullptr)
	{
		combatant1->creatureInfo();
	}
}

void BattleManager::SetCreature2(Creature* p2, BattleInfo* b2)
{
	combatant2 = p2;
	bInfo2 = b2;

	if (combatant2 != nullptr)
	{
		combatant2->creatureInfo();
	}

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
		if (combatant1->getStat(SPEED) < combatant2->getStat(SPEED))
		{
			moveOrder = false;
		}
		else if (combatant1->getStat(SPEED) == combatant2->getStat(SPEED))
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

bool BattleManager::TryAttack(Creature* target, BattleInfo* targetInfo)
{
	return true;
}

void BattleManager::ApplyAttack(Creature* active, BattleInfo* activeInfo, Creature* target, BattleInfo* targetInfo)
{
	activeInfo->GetCurrentMove()->Attack(target);

	cout << active->getName() << " attacked " << target->getName() << " with " << activeInfo->GetCurrentMove()->getName() << ".\n";
}

void BattleManager::EndOfTurnStatus()
{
	bInfo1->StatusEndOfTurn();
	bInfo2->StatusEndOfTurn();
}


void BattleManager::CreatureTurn(Creature* active, BattleInfo* activeInfo, Creature* target, BattleInfo* targetInfo)
{

	BeforeMoveStatusEffects(activeInfo);

	if (TryAttack(target, targetInfo))
	{
		ApplyAttack(active, activeInfo, target, targetInfo);
	}
}

void BattleManager::Turn()
{
	bool moveOrder = DeterminePriority();

	if (moveOrder)
	{
		//1 moves first
		//2 moves second

		CreatureTurn(combatant1, bInfo1, combatant2, bInfo2);
		CreatureTurn(combatant2, bInfo2, combatant1, bInfo1);
	}
	else
	{
		//2 moves first
		//1 moves second

		CreatureTurn(combatant2, bInfo2, combatant1, bInfo1);
		CreatureTurn(combatant1, bInfo1, combatant2, bInfo2);
	}

	EndOfTurnStatus();

}

