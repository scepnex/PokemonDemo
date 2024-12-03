#include "Status.h"
#include "BattleInfo.h"
#include "Move.h"

void Freeze::Attach(BattleInfo* appliedTo)
{
	appliedTo_ = appliedTo;
	appliedTo->AddBeforeMoveEffect(this);
}

void Freeze::Detach(BattleInfo* appliedTo)
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