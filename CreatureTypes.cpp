#include <CreatureTypes.h>

CreatureTypes::CreatureTypes()
{
	for (int i = 0; i < NUM_TYPES; i++)
	{
		for (int j = 0; j < NUM_TYPES; j++)
		{
			typeMatrix[i][j] = NEUTRAL;
		}
	}

	//NORMAL
	typeMatrix[NORMAL][ROCK] = HALF;
	typeMatrix[NORMAL][STEEL] = HALF;
	typeMatrix[NORMAL][GHOST] = ZERO;

	//FIGHTING 
	typeMatrix[FIGHTING][NORMAL] = DOUBLE;
	typeMatrix[FIGHTING][ROCK] = DOUBLE;
	typeMatrix[FIGHTING][STEEL] = DOUBLE;
	typeMatrix[FIGHTING][ICE] = DOUBLE;
	typeMatrix[FIGHTING][DARK] = DOUBLE;

	typeMatrix[FIGHTING][FLYING] = HALF;
	typeMatrix[FIGHTING][POISON] = HALF;
	typeMatrix[FIGHTING][BUG] = HALF;
	typeMatrix[FIGHTING][PSYCHIC] = HALF;
	typeMatrix[FIGHTING][FAIRY] = HALF;

	typeMatrix[FIGHTING][GHOST] = ZERO;

	//FLYING
	typeMatrix[FLYING][FIGHTING] = DOUBLE;
	typeMatrix[FLYING][BUG] = DOUBLE;
	typeMatrix[FLYING][GRASS] = DOUBLE;

	typeMatrix[FLYING][ROCK] = HALF;
	typeMatrix[FLYING][STEEL] = HALF;
	typeMatrix[FLYING][ELECTRIC] = HALF;


	//POISON
	typeMatrix[POISON][GRASS] = DOUBLE;
	typeMatrix[POISON][FAIRY] = DOUBLE;

	typeMatrix[POISON][POISON] = HALF;
	typeMatrix[POISON][GROUND] = HALF;
	typeMatrix[POISON][ROCK] = HALF;
	typeMatrix[POISON][GHOST] = HALF;
	typeMatrix[POISON][GHOST] = HALF;

	typeMatrix[POISON][STEEL] = ZERO;

	//GROUND
	typeMatrix[GROUND][POISON] = DOUBLE;
	typeMatrix[GROUND][ROCK] = DOUBLE;
	typeMatrix[GROUND][STEEL] = DOUBLE;
	typeMatrix[GROUND][FIRE] = DOUBLE;
	typeMatrix[GROUND][ELECTRIC] = DOUBLE;

	typeMatrix[GROUND][BUG] = HALF;
	typeMatrix[GROUND][GRASS] = HALF;

	typeMatrix[GROUND][FLYING] = ZERO;

	//ROCK
	typeMatrix[ROCK][FLYING] = DOUBLE;
	typeMatrix[ROCK][BUG] = DOUBLE;
	typeMatrix[ROCK][FIRE] = DOUBLE;
	typeMatrix[ROCK][ICE] = DOUBLE;

	typeMatrix[ROCK][FIGHTING] = HALF;
	typeMatrix[ROCK][GROUND] = HALF;
	typeMatrix[ROCK][STEEL] = HALF;

	//BUG
	typeMatrix[BUG][GRASS] = DOUBLE;
	typeMatrix[BUG][PSYCHIC] = DOUBLE;
	typeMatrix[BUG][DARK] = DOUBLE;

	typeMatrix[BUG][FIGHTING] = HALF;
	typeMatrix[BUG][FLYING] = HALF;
	typeMatrix[BUG][POISON] = HALF;
	typeMatrix[BUG][GHOST] = HALF;
	typeMatrix[BUG][STEEL] = HALF;
	typeMatrix[BUG][FIRE] = HALF;
	typeMatrix[BUG][FAIRY] = HALF;

	//GHOST

	//STEEL

	//FIRE

	//WATER
	typeMatrix[WATER][FIRE] = DOUBLE;
	typeMatrix[WATER][GROUND] = DOUBLE;
	typeMatrix[WATER][ROCK] = DOUBLE;

	typeMatrix[WATER][WATER] = HALF;
	typeMatrix[WATER][GRASS] = HALF;
	typeMatrix[WATER][DRAGON] = HALF;


	//GRASS

	//ELECTRIC

	//PSYCHIC

	//ICE

	//DRAGON

	//DARK

	//FAIRY
}

std::string CreatureTypes::checkEffective(Types attackingMoveType, Types defendingCreatureType)
{
	switch (typeMatrix[attackingMoveType][defendingCreatureType])
	{
	case ZERO:
		return "doesn't affect";
	case HALF:
		return "not very effective";
	case NEUTRAL:
		return "regular";
	case DOUBLE:
		return "super effective!";
	}
}