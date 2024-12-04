#include <string>
#include <iostream>
#include <creature.h>

using namespace std;


void Creature::setBaseStats(int hp, int atk, int def, int spAtk, int spDef, int spd)
{
	setBaseStat(HEALTH, hp);
	setBaseStat(ATTACK, atk);
	setBaseStat(DEFENSE, def);
	setBaseStat(SPATK, spAtk);
	setBaseStat(SPDEF, spDef);
	setBaseStat(SPEED, spd);
}

void Creature::creatureInfo()
{
	cout << "Name: " << name << '\n';
	cout << "Level: " << level << '\n';

	cout << "\nBase Stats:";
	cout << "\nHP: " << baseStats[HEALTH] << '\n';
	cout << "Attack: " << baseStats[ATTACK] << '\n';
	cout << "Defense: " << baseStats[DEFENSE] << '\n';
	cout << "Sp.Attack: " << baseStats[SPATK] << '\n';
	cout << "Sp.Defense: " << baseStats[SPDEF] << '\n';
	cout << "Speed: " << baseStats[SPEED] << '\n';

	cout << "\nLeveled Stats:";
	cout << "\nHP: " << currentHealth << "/" << leveledStats[HEALTH] << '\n';
	cout << "Attack: " << leveledStats[ATTACK] << '\n';
	cout << "Defense: " << leveledStats[DEFENSE] << '\n';
	cout << "Sp.Attack: " << leveledStats[SPATK] << '\n';
	cout << "Sp.Defense: " << leveledStats[SPDEF] << '\n';
	cout << "Speed: " << leveledStats[SPEED] << '\n';


}

void Creature::setStats()
{
	setStat(HEALTH);
	setStat(ATTACK);
	setStat(DEFENSE);
	setStat(SPATK);
	setStat(SPDEF);
	setStat(SPEED);

	currentHealth = leveledStats[HEALTH];
}

void Creature::setStat(Stats stat)
{
	float result = 0.f;

	if (stat == HEALTH)
	{
		result = (static_cast<float>(baseStats[HEALTH]) * 2.f * static_cast<float>(level)) / 100.f + static_cast<float>(level) + 10.f;
	}
	else
	{
		result = (static_cast<float>(baseStats[stat]) * 2.f * static_cast<float>(level)) / 100.f + 5.f;
	}

	leveledStats[stat] = static_cast<int>(result);
}

void Creature::damage(int value)
{
	cout << "    " << name << " damaged for " << value << "\n";
	currentHealth -= value;

	if (currentHealth < 0)
		currentHealth = 0;

	cout << "    HP: " << currentHealth << "/" << getStat(HEALTH) << endl;
}

void Creature::applyStatus(string txt)
{
	cout << txt << endl;
}

Cloyster::Cloyster()
{
	name = "Cloyster";
	level = 1;
	type1 = WATER;
	type2 = ICE;

	setBaseStats(50, 95, 180, 85, 45, 70);
	setStats();

}

Forretress::Forretress()
{
	name = "Forretress";
	level = 1;

	type1 = BUG;
	type2 = STEEL;

	setBaseStats(75, 90, 140, 60, 60, 80);
	setStats();

}