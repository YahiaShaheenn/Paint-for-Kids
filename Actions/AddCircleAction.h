#ifndef ADD_CIRCLE_ACTION_H
#define ADD_CIRCLE_ACTION_H
#include"Action.h"

class AddCircleAction :public Action {
private:

	Point P1;
	Point P2;

	GfxInfo CircGfxInfo;


public:

	AddCircleAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();
};
#endif