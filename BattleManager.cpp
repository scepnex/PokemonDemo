#include "BattleManager.h"

void BattleManager::Turn()
{

	int priority1 = bInfo1.priority();
	int priority2 = bInfo2.priority();

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
		if (combatant1.getStat(SPEED) < combatant2.getStat(SPEED))
		{
			moveOrder = false;
		}
		else if (combatant1.getStat(SPEED) == combatant2.getStat(SPEED))
		{
			//choose random pokemon to go first
		}
	}

	if (moveOrder)
	{
		//1 moves first
		//2 moves second
	}
	else
	{
		//2 moves first
		//1 moves second
	}
}