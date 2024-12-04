#include "Status.h"
#include "BattlePkmn.h"
#include "Move.h"

void Freeze::Attach(BattlePkmn* appliedTo)
{
	appliedTo_ = appliedTo;
	appliedTo->AddBeforeMoveEffect(this);
}

void Freeze::Detach(BattlePkmn* appliedTo)
{
	appliedTo_ = nullptr;
	appliedTo->RemoveBeforeMoveEffect(this);
}

void Freeze::BeforeMove()
{
	//guaranteed thaw under certain conditions (powerful fire move)
	//chance of thawing
	//else, frozen message
	cout << appliedTo_->getName() << " is frozen! no moves this turn.\n";
	appliedTo_->GetCurrentMove()->cancelMove();
}

void Burn::Attach(BattlePkmn* appliedTo)
{
	appliedTo_ = appliedTo;
	appliedTo->AddEndOfTurnEffect(this);

}
void Burn::Detach(BattlePkmn* appliedTo)
{
	appliedTo_ = nullptr;
	appliedTo->RemoveEndOfTurnEffect(this);

}

void Burn::EndOfTurn()
{
	//apply burn damage
	int burnDmg = appliedTo_->getStat(HEALTH) / 8;
	cout << appliedTo_->getName() << " was hurt by its burn for " << burnDmg << "\n";
	appliedTo_->Damage(burnDmg);

}
void Burn::OnApplyStatus()
{
	//apply burn debuff
}
void Burn::OnRemoveStatus()
{
	//remove burn debuff
}