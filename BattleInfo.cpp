#include "BattleInfo.h"
#include "Move.h"

float BattleInfo::getStatMod(Stats stat)
{
	return statMods.getStatMod(stat);
}

int BattleInfo::priority()
{
	int result = -1;

	if (currentMove != nullptr)
	{
		result = currentMove->movePriority();
	}

	return result;
}

void BattleInfo::StatusEffectBeforeMove()
{
	if (statusEffect != nullptr)
	{
		statusEffect->BeforeMove();
	}

	for (int i = 0; i < volatileStatuses.size(); i++)
	{
		volatileStatuses[i]->BeforeMove();
	}
}

void BattleInfo::StatusEndOfTurn()
{
	if (statusEffect != nullptr)
	{
		statusEffect->EndOfTurn();
	}

	for (int i = 0; i < volatileStatuses.size(); i++)
	{
		volatileStatuses[i]->EndOfTurn();
	}
}

void BattleInfo::ApplyStatus(SolidStatus* effect)
{
	if (statusEffect == nullptr)
	{
		statusEffect = effect;
	}
}


void BattleInfo::ApplyVolatileStatus(VolatileStatus* effect)
{
	// add a volatile status effect to the list
}

void BattleInfo::Damage(int value, Types type)
{
	//receive damage from a creature's attack
	parent_.damage(value);
	
}