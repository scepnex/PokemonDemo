/**
 * The Command interface declares a method for executing a command.
 */
#pragma once

class MoveCommand {
public:
	virtual ~MoveCommand() {}
	virtual void Execute() = 0;
};
