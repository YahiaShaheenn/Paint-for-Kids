#ifndef ADD_SQU_ACTION_H
#define ADD_SQU_ACTION_H
#include"Action.h"

class AddSquareAction :public Action {
private:

	Point P1;

	GfxInfo SquGfxInfo;


public:

	AddSquareAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();
};


#endif