#pragma once

#include <string>

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
public:
	Effective typeMatrix[NUM_TYPES][NUM_TYPES];

	CreatureTypes();

	std::string checkEffective(Types attackingMoveType, Types defendingCreatureType);
};