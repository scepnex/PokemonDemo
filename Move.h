#pragma once

#include <Creature.h>
//#include <CreatureTypes.h>
#include <Status.h>
#include <string>
#include <vector>
#include <iostream>
#include <BattlePkmn.h>
#include <MoveCommand.h>
#include <UsefulFunctions.h>


using namespace std;

class MoveComponent
{
public:

	MoveComponent() {}
	virtual ~MoveComponent() {}

	virtual void Apply(BattlePkmn* sender, BattlePkmn* target) = 0;
	virtual void print() = 0;

	bool operator == (const MoveComponent& rhs) const { return *this == rhs; }
};

class Damage : public MoveComponent
{
protected:
	float power = 0.f; // float type for ease of reading code. Use whole numbers for moves
	Types moveType_ = TYPE_NONE;

public:
	Damage(float value, Types moveType) : power(value), moveType_(moveType) {}

	void Apply(BattlePkmn* sender, BattlePkmn* target) override;
	void print() override { cout << "Damage for " << power; }
};

class StatusEffect : public MoveComponent
{
protected:
	SolidStatus* effect;
	float successRate = 0.f;
public:
	StatusEffect(SolidStatus* _effect, float rate) : effect(_effect), successRate(rate) {}

	void Apply(BattlePkmn* sender, BattlePkmn* target) override
	{
		float chance = UsefulFunctions::randomFloat();

		if (chance <= successRate)
		{
			target->ApplyStatus(effect);
		}
	}
	void print() override { cout << "Effect success rate is " << successRate << '%'; }
};

class VolatileEffect : public MoveComponent
{
protected:
	VolatileStatus* effect;
	float successRate = 0.f;
public:
	VolatileEffect(VolatileStatus* _effect, float rate) : effect(_effect), successRate(rate) {}

	void Apply(BattlePkmn* sender, BattlePkmn* target) override
	{
		target->ApplyVolatileStatus(effect);
	}
	void print() override { cout << "Effect success rate is " << successRate << '%'; }
};


/*
	

*/
class Move : public MoveCommand
{
protected:
	std::string name;
	std::string battleEffect;

	Types attackType =	TYPE_NONE;
	int powerPoints = 0;
	float accuracy = 0.f;
	int priority = 0;

	std::vector<MoveComponent*> elements;
	BattlePkmn& owner_;
	BattlePkmn* target_ = nullptr;

	bool canceled_ = false;

public:
	explicit Move(BattlePkmn& owner) : owner_(owner) {}
	std::string getName() { return name; }

	float getAccuracy() { return accuracy; }
	int movePriority() { return priority; }
	int speedPriority() { return owner_.getStat(SPEED); }

	virtual void onSelectMove() {}
	void cancelMove() { canceled_ = true; }
	bool getCanceled() { return canceled_; }

	void AddComponent(MoveComponent* comp)
	{
		elements.push_back(comp);
	}

	void SetTarget(BattlePkmn* target) { target_ = target; }

	void print()
	{
		cout << "Name: " << name << endl;
		cout << "Power pts: " << powerPoints << endl;
		cout << "Accuracy: " << accuracy << endl;
		cout << "Effect: " << battleEffect << endl;

	}

	void ListParts() {
		print();
		std::cout << "\nThis move consists of:\n";
		for (int i = 0; i < elements.size(); i++)
		{
			if (elements[i] == elements.back())
			{
				elements[i]->print();
			}
			else
			{
				elements[i]->print();
				cout << ". ";
			}
		}
		cout << endl;
	}

	bool AccuracyCheck()
	{
		cout << owner_.getName() << " used " << name << "!\n";

		bool result = false;

		float modifierTotal = owner_.getStatMod(ACCURACY) * target_->getStatMod(EVASION);

		float accuracyRoll = UsefulFunctions::randomFloat() * 100.f;

		float modifierCalc = accuracy * modifierTotal;

		result = accuracyRoll <= modifierCalc;

		cout << "    Accuracy roll: " << accuracyRoll << " <= " << modifierCalc << endl;

		return result;
	}

	void Execute() override
	{
		owner_.StatusEffectsBeforeMove();
		if (canceled_ == false)
		{
			// accuracy check
			bool hit = AccuracyCheck();
			if (hit)
			{
				for (int i = 0; i < elements.size(); i++)
				{
					elements[i]->Apply(&owner_, target_);
				}
			}
			else
			{
				//attack missed phase
				cout << "    the attack missed!\n";
			}
		}
	}
};

class MoveBlizzard : public Move
{
public:
	MoveBlizzard(BattlePkmn &owner);
};

class MoveEmber : public Move
{
public:
	MoveEmber(BattlePkmn& owner);
};

class MoveFocusPunch : public Move
{
public:
	MoveFocusPunch(BattlePkmn& owner);
	void onSelectMove() override;
};