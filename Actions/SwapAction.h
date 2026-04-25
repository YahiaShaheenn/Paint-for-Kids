#ifndef SWAP_ACTION_H
#define SWAP_ACTION_H

#include "Action.h"
class SwapAction : public Action
{
public:
	SwapAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();

};

#endif