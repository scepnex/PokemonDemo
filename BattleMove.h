#pragma once

#include <Creature.h>
#include <CreatureTypes.h>
#include <Status.h>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class MoveComponent
{
public:

	MoveComponent() {}
	virtual ~MoveComponent() {}

	virtual void Apply(Types type, Creature* target) = 0;
	virtual void print() = 0;

	bool operator == (const MoveComponent& rhs) const
	{
		return *this == rhs;
	}
};

class Damage : public MoveComponent
{
protected:
	int power = 0;

public:
	Damage(int value) : power(value) {}

	void Apply(Types type, Creature* target) override { target->damage(power); }
	void print() override { cout << "Damage for " << power; }
};

class Effect : public MoveComponent
{
protected:
	Status* effect;
	int successRate = 0;
public:
	Effect(Status* _effect, int rate) : effect(_effect), successRate(rate) {}

	void Apply(Types type, Creature* target) override { target->applyStatus("Effect applied."); }
	void print() override { cout << "Effect success rate is " << successRate << '%'; }
};


class BattleMove
{
protected:
	std::string name;
	std::string battleEffect;
	Types attackType =	TYPE_NONE;
	int powerPoints = 0;
	int accuracy = 0;
	int priority = 0;

	std::vector<MoveComponent*> elements;

public:
	std::string getName() { return name; }

	int movePriority() { return priority; }

	void AddComponent(MoveComponent* comp)
	{
		elements.push_back(comp);
	}

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

	void Attack(Creature* target)
	{
		for (int i = 0; i < elements.size(); i++)
		{
			elements[i]->Apply(attackType, target);
		}
	}
};

class MoveBlizzard : public BattleMove
{
public:
	MoveBlizzard()
	{
		name = "Blizzard";
		battleEffect = "Strongest ICE attack. Might Freeze Target.";
		attackType = ICE;
		powerPoints = 5;
		accuracy = 70;

		AddComponent(new Damage(120));
		AddComponent(new Effect(new Freeze(), 10));
	}
};

class MoveEmber : public BattleMove
{
public:
	MoveEmber();
};