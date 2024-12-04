#pragma once

#include <string>

class BattlePkmn;

class Status
{
protected:
	BattlePkmn* appliedTo_;
	std::string name_;

public:
	virtual ~Status() {}

	virtual void Attach(BattlePkmn* appliedTo) = 0;
	virtual void Detach(BattlePkmn* appliedTo) = 0;

	virtual void OnApplyStatus() = 0;
	virtual void OnRemoveStatus() = 0;

	virtual void OnStartTurn() = 0;
	virtual void BeforeMove() = 0;
	virtual void AfterMove() = 0;
	virtual void EndOfTurn() = 0;
	virtual void OnHitPhase() = 0;

	std::string getName() { return name_; }

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
	Freeze() { name_ = "Freeze"; }
	void Attach(BattlePkmn* appliedTo) override;
	void Detach(BattlePkmn* appliedTo) override;

	void BeforeMove() override;
};

//class Paralyzed : public SolidStatus
//{
//public:
//	void Attach(BattlePkmn* appliedTo) override;
//	void Detach(BattlePkmn* appliedTo) override;
//
//	void BeforeMove() override;
//	void OnApplyStatus() override;
//	void OnRemoveStatus() override;
//};

class Burn : public SolidStatus
{
public:
	Burn() { name_ = "Burn"; }
	void Attach(BattlePkmn* appliedTo) override;
	void Detach(BattlePkmn* appliedTo) override;

	void EndOfTurn() override;
	void OnApplyStatus() override;
	void OnRemoveStatus() override;
};

class FocusPunchStatus : public VolatileStatus
{
public:
	FocusPunchStatus() { name_ = "Focus Punch status"; }
	void Attach(BattlePkmn* appliedTo) override;
	void Detach(BattlePkmn* appliedTo) override;

	void OnStartTurn() override;
	void OnHitPhase() override;
	void BeforeMove() override;
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