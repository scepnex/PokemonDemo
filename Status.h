#pragma once

class BattleInfo;

class Status
{
protected:
	BattleInfo* appliedTo_;

public:
	virtual ~Status() {}

	virtual void Attach(BattleInfo* appliedTo) = 0;
	virtual void Detach(BattleInfo* appliedTo) = 0;

	virtual void OnApplyStatus() = 0;
	virtual void OnRemoveStatus() = 0;

	virtual void OnStartTurn() = 0;
	virtual void BeforeMove() = 0;
	virtual void AfterMove() = 0;
	virtual void EndOfTurn() = 0;
	virtual void OnHitPhase() = 0;

};

class SolidStatus : public Status
{
public:
	virtual ~SolidStatus() {}

	void OnApplyStatus() {}
	void OnRemoveStatus() {}

	void OnStartTurn() {}
	void BeforeMove() {}
	void AfterMove() {}
	void EndOfTurn() {}
	void OnHitPhase() {}
};

class VolatileStatus : public Status
{
public:
	virtual ~VolatileStatus() {}

	void OnApplyStatus() {}
	void OnRemoveStatus() {}

	void OnStartTurn() {}
	void BeforeMove() {}
	void AfterMove() {}
	void EndOfTurn() {}
	void OnHitPhase() {}
};

class Freeze : public SolidStatus
{
public:

	void Attach(BattleInfo* appliedTo) override;
	void Detach(BattleInfo* appliedTo) override;

	void BeforeMove() override;
};

class Paralyzed : public SolidStatus
{
public:
	void Attach(BattleInfo* appliedTo) override;
	void Detach(BattleInfo* appliedTo) override;

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
	void Attach(BattleInfo* appliedTo) override {}
	void Detach(BattleInfo* appliedTo) override {}

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

//class Flinch : public VolatileStatus
//{
//public:
//	void BeforeMove() override
//	{
//		//chance of interrupt move
//	}
//	void EndOfTurn() override
//	{
//		//remove status
//	}
//};