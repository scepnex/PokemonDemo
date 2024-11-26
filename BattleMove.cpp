#include "BattleMove.h"

MoveEmber::MoveEmber()
{
	name = "Ember";;
	battleEffect = "Basic FIRE attack.";
	attackType = FIRE;
	powerPoints = 25;
	accuracy = 100;

	AddComponent(new Damage(40));
	AddComponent(new Effect(new Burn(), 10));
}