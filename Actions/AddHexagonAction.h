#ifndef ADD_HEX_ACTION_H
#define ADD_HEX_ACTION_H
#include"Action.h"

class AddHexagonAction :public Action {
private:

	Point P1;

	GfxInfo HexGfxInfo;


public:

	AddHexagonAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();

};


#endif