#pragma once

#include <iostream>
#include <mutex>

using namespace std;

enum Types {
	TYPE_NONE = 0, // ??? type for Eggs, special case attacks.
	NORMAL,
	FIGHTING,
	FLYING,
	POISON,
	GROUND,
	ROCK,
	BUG,
	GHOST,
	STEEL,
	FIRE,
	WATER,
	GRASS,
	ELECTRIC,
	PSYCHIC,
	ICE,
	DRAGON,
	DARK,
	FAIRY,
	NUM_TYPES //for array length
};

enum Effective {
	ZERO = 0,
	HALF,
	NEUTRAL,
	DOUBLE
};

class CreatureTypes {

private:
	static CreatureTypes* instance;
	static mutex mtx;
	CreatureTypes();

public:
	// Deleting the copy constructor to prevent copies
	CreatureTypes(const CreatureTypes& obj) = delete;

	// Static method to get the Singleton instance
	static CreatureTypes* getInstance() {
		if (instance == nullptr) {
			lock_guard<mutex> lock(mtx);
			if (instance == nullptr) {
				instance = new CreatureTypes();
			}
		}
		return instance;
	}

	Effective typeMatrix[NUM_TYPES][NUM_TYPES];


	std::string checkEffective(Types attackingMoveType, Types defendingCreatureType);
	static float getMultiplier(Types attack, Types defend);
};