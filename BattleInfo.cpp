#include "BattleInfo.h"


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