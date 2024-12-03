/**
 * The Command interface declares a method for executing a command.
 */
#pragma once

class BattleInfo;

class MoveCommand {
public:
	virtual ~MoveCommand() {}
	virtual void Execute(BattleInfo* sender, BattleInfo* target) const = 0;
};
