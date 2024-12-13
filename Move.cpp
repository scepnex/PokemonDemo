#include "Move.h"
#include "CreatureTypes.h"

void Damage::Apply(BattlePkmn* sender, BattlePkmn* target)
{
	float result = 2.2f * power * sender->getStat(ATTACK) / target->getStat(DEFENSE);

	float STAB = 1.f; //Same-type attack bonus
	if (moveType_ == sender->getType(1) || moveType_ == sender->getType(2))
	{
		STAB = 1.5f;
		cout << "    user type and move type same, STAB applies. \n";
	}

	//effectivity
	float effective = CreatureTypes::getMultiplier(moveType_, target->getType(1))
		* CreatureTypes::getMultiplier(moveType_, target->getType(2));

	cout << "    ";

	if (effective >= 2)
	{
		cout << "Super effective! ";
	}
	if (effective <= 0.5 && effective > 0)
	{
		cout << "Not very effective... ";
	}
	if (effective <= 0)
	{
		cout << "It had no effect! ";
	}

	cout << "(damage x" << effective << ") \n";

	result *= effective * STAB;

	target->Damage(int(result), moveType_);
	target->OnDamage(sender);
}

MoveEmber::MoveEmber(BattlePkmn& owner) : Move(owner)
{
	name = "Ember";;
	battleEffect = "Basic FIRE attack.";
	attackType = FIRE;
	powerPoints = 25;
	accuracy = 100.f;

	AddComponent(new Damage(40, attackType));
	AddComponent(new StatusEffect(new Burn(), 0.7f));
}

MoveBlizzard::MoveBlizzard(BattlePkmn& owner) : Move(owner)
{
	name = "Blizzard";
	battleEffect = "Strongest ICE attack. Might Freeze Target.";
	attackType = ICE;
	powerPoints = 5;
	accuracy = 70.f;
	priority = 0;

	AddComponent(new Damage(120, attackType));
	AddComponent(new StatusEffect(new Freeze(), 0.7f));
}

void MoveFocusPunch::onSelectMove()
{
	owner_.ApplyVolatileStatus(new FocusPunchStatus());
}

MoveFocusPunch::MoveFocusPunch(BattlePkmn& owner) : Move(owner)
{
	name = "Focus Punch";
	battleEffect = "The user focuses its mind before launching a punch. It will fail if the user is hit before it is used";
	attackType = FIGHTING;
	powerPoints = 20;
	accuracy = 100.f;
	priority = -3;

	AddComponent(new Damage(150, attackType));
}