#pragma once

#include <stdlib.h>
#include <CreatureTypes.h>

class UsefulFunctions {

public:
	static float randomFloat()
	{
		rand(); // we added a call to rand here because i did not feel like dealing with a better solution for c++ randomness
		return (float)(rand()) / (float)(RAND_MAX);
	}

};
