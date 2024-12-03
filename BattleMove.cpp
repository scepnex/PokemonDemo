#include "BattleMove.h"

MoveEmber::MoveEmber()
{
	name = "Ember";;
	battleEffect = "Basic FIRE attack.";
	attackType = FIRE;
	powerPoints = 25;
	accuracy = 100.f;

	AddComponent(new Damage(40, attackType));
	AddComponent(new StatusEffect(new Burn(), 10));
}

MoveBlizzard::MoveBlizzard()
{
	name = "Blizzard";
	battleEffect = "Strongest ICE attack. Might Freeze Target.";
	attackType = ICE;
	powerPoints = 5;
	accuracy = 70.f;

	AddComponent(new Damage(120, attackType));
	AddComponent(new StatusEffect(new Freeze(), 10));
}