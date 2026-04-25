#ifndef ROTATE_ACTION_H
#define ROTATE_ACTION_H

#include "Action.h"

class RotateAction :public Action {
public:
	RotateAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();

};
#endif