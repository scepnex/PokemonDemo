#pragma once
class Status
{
public:
	Status () {}
	virtual void OnApplyStatus() = 0;
	virtual void OnRemoveStatus() = 0;
	virtual void BeforeMove() = 0;
	virtual void EndOfTurn() = 0;
};

class SolidStatus : public Status
{
public:
	SolidStatus() {}
	void BeforeMove() override {}
	void EndOfTurn() override {}
	void OnApplyStatus() override {}
	void OnRemoveStatus() override {}
};

class VolatileStatus : public Status
{
public:
	VolatileStatus() {}
	void BeforeMove() override {}
	void EndOfTurn() override {}
	void OnApplyStatus() override {}
	void OnRemoveStatus() override {}
};

class Freeze : public SolidStatus
{
public:
	//Freeze() {}

	void BeforeMove() override 
	{
		//guaranteed thaw under certain conditions (powerful fire move)
		//chance of thawing
		//else, frozen message
	}
};

class Paralyzed : public SolidStatus
{
public:
	Paralyzed() {}
	void BeforeMove() override
	{
		//chance of interrupt move
	}
	void OnApplyStatus() override
	{
		//apply speed debuff
	}
	void OnRemoveStatus() override
	{
		//remove speed debuff
	}
};

class Burn : public SolidStatus
{
public:
	Burn() {}
	void EndOfTurn() override
	{
		//apply burn damage
	}
	void OnApplyStatus() override
	{
		//apply burn debuff
	}
	void OnRemoveStatus() override
	{
		//remove burn debuff
	}
};

class Flinch : public VolatileStatus
{
public:
	Flinch() {}
	void BeforeMove() override
	{
		//chance of interrupt move
	}
	void EndOfTurn() override
	{
		//remove status
	}
};