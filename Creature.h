#pragma once

#ifndef __CREATURE_H_INCLUDED__
#define __CREATURE_H_INCLUDED__

#include <iostream>
#include <string>
#include <map>
#include <CreatureTypes.h>

enum Stats
{
	HEALTH,
	ATTACK,
	DEFENSE,
	SPATK,
	SPDEF,
	SPEED,
	EVASION,
	ACCURACY,
	NUM_BASESTATS
};

class Creature
{
protected:
	std::string name;
	//std::string nickname;

	//Main Stats
	int level = 0;
	
	int baseStats[NUM_BASESTATS] = { 0, 0, 0, 0, 0, 0 };
	int leveledStats[NUM_BASESTATS] = { 0, 0, 0, 0, 0, 0 };

	Types type1 = TYPE_NONE;
	Types type2 = TYPE_NONE;

public:
	//other stats, stuff that might change in battle
	int currentHealth = 0;

	Creature() {}

	void creatureInfo();

	Types getType1() { return type1; }
	Types getType2() { return type2; }

	void setLevel(int lvl) { level = lvl; }
	void setBaseStats(int hp, int atk, int def, int spAtk, int spDef, int spd);
	void setBaseStat(Stats stat, int value) { baseStats[stat] = value; }

	void setStats();
	void setStat(Stats stat);

	int getStat(Stats stat) const { return leveledStats[stat]; }
	std::string getName() { return name; }

	void damage(int value);
	void applyStatus(std::string txt);

	virtual ~Creature() {}
	//virtual Creature* Clone() const = 0;

};


class Cloyster : public Creature
{
public:
	Cloyster();
};

class Forretress : public Creature
{
public:
	Forretress();
};

#endif