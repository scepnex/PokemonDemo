#include "BattlePkmn.h"
#include "Move.h"

float BattlePkmn::getStatMod(Stats stat)
{
	return statMods.getStatMod(stat);
}

int BattlePkmn::priority()
{
	int result = -1;

	if (currentMove != nullptr)
	{
		result = currentMove->movePriority();
	}

	return result;
}

void BattlePkmn::StatusEffectsBeforeMove()
{
	std::list<Status*>::iterator iterator = effectBeforeMove.begin();
	while (iterator != effectBeforeMove.end())
	{
		(*iterator)->BeforeMove();
		++iterator;
	}

}

void BattlePkmn::StatusEffectsEndOfTurn()
{
	std::list<Status*>::iterator iterator = effectOnTurnEnd.begin();

	while (iterator != effectOnTurnEnd.end())
	{
		(*iterator)->EndOfTurn();
		++iterator;
	}
}

void BattlePkmn::ApplyStatus(SolidStatus* effect)
{

	if (statusEffect == nullptr)
	{

		cout << getName() << " has been afflicted with " << effect->getName() << endl;
		statusEffect = effect;
		effect->Attach(this);
	}
}


void BattlePkmn::ApplyVolatileStatus(VolatileStatus* effect)
{
	// add a volatile status effect to the list
}

void BattlePkmn::Damage(int value, Types type)
{
	//receive damage from a creature's attack
	parent_.damage(value);
	
}