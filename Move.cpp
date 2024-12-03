#include "Move.h"

void Damage::Apply(BattleInfo* sender, BattleInfo* target)
{
	float result = 2.2f * power * sender->getStat(ATTACK) / target->getStat(DEFENSE);


	
	target->Damage(int(result), moveType_);
}

MoveEmber::MoveEmber(BattleInfo& owner) : Move(owner)
{
	name = "Ember";;
	battleEffect = "Basic FIRE attack.";
	attackType = FIRE;
	powerPoints = 25;
	accuracy = 100.f;

	AddComponent(new Damage(40, attackType));
	AddComponent(new StatusEffect(new Burn(), 10));
}

MoveBlizzard::MoveBlizzard(BattleInfo& owner) : Move(owner)
{
	name = "Blizzard";
	battleEffect = "Strongest ICE attack. Might Freeze Target.";
	attackType = ICE;
	powerPoints = 5;
	accuracy = 70.f;
	priority = 0;

	AddComponent(new Damage(120, attackType));
	AddComponent(new StatusEffect(new Freeze(), 10));
}