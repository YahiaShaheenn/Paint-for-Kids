#include "ApplicationManager.h"
#include "Actions\AddRectAction.h"
#include"Actions\AddTriangleAction.h"
#include"Actions\AddSquareAction.h"
#include"Actions\AddCircleAction.h"
#include"Actions\AddHexagonAction.h"
#include"Actions\SelectAction.h"
#include"Actions\SwapAction.h"
#include "Actions\SwitchToPlayAction.h"
#include "Actions\RotateAction.h"

//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();
	
	FigCount = 0;
		
	//Create an array of figure pointers and set them to NULL		
	for(int i=0; i<MaxFigCount; i++)
		FigList[i] = NULL;	
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
ActionType ApplicationManager::GetUserAction() const
{
	//Ask the input to get the action from the user.
	return pIn->GetUserAction();		
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType) 
{
	Action* pAct = NULL;
	
	//According to Action Type, create the corresponding action object
	switch (ActType)
	{
		case DRAW_RECT:
			pAct = new AddRectAction(this);
			break;

		case DRAW_TRI:
			pAct = new AddTriangleAction(this);
			break;

		case DRAW_SQU:
			pAct = new AddSquareAction(this);
			break;

		case DRAW_CIRC:
			pAct = new AddCircleAction(this);
			break;

		case DRAW_HEX:
			pAct = new AddHexagonAction(this);
			break;

		case SELECT:
			pAct = new SelectAction(this);
			break;

		case SWAP:
			pAct = new SwapAction(this);
			break;

		case ROTATE_FIG:
			pAct = new RotateAction(this);

		case EXIT:
			///create ExitAction here
			
			break;
		
		case STATUS:	//a click on the status bar ==> no action
			return;
	}
	
	//Execute the created action
	if(pAct != NULL)
	{
		pAct->Execute();//Execute
		delete pAct;	//You may need to change this line depending to your implementation
		pAct = NULL;
	}
}
//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{
	if (FigCount < MaxFigCount)
	{
		FigList[FigCount++] = pFig;
		pFig->setID(FigCount);
	}
}
////////////////////////////////////////////////////////////////////////////////////
CFigure *ApplicationManager::GetFigure(int x, int y) const
{
	//If a figure is found return a pointer to it.
	//if this point (x,y) does not belong to any figure return NULL
	for (int i = FigCount - 1; i >= 0; i--)
	{
		if (FigList[i] != nullptr && FigList[i]->IsInside(x, y))
			return FigList[i];
	}

	//Add your code here to search for a figure given a point x,y	
	//Remember that ApplicationManager only calls functions do NOT implement it.

	return nullptr;
}

bool ApplicationManager::GetTwoSelectedFigures(CFigure*& fig1, CFigure*& fig2) const
{
	int found = 0;

	fig1 = nullptr;
	fig2 = nullptr;

	for (int i = 0; i < FigCount; i++) {

		if (FigList[i]->IsSelected()) {

			if (found == 0)
				fig1 = FigList[i];

			else if (found == 1)
				fig2 = FigList[i];

			found++;

			if (found > 2)
				break;
		}
	}
	if (found == 2)
		return true;

	else
		return false;
}
void ApplicationManager::SwapInFigList()
{

	for (int i = FigCount - 1; i >= 0; i--) {

		if (FigList[i]->IsSelected()) {

			for (int j = i-1; j >= 0; j--) {

				if (FigList[j]->IsSelected()) {
					CFigure* x = FigList[i]->Clone();
					CFigure* y = FigList[j]->Clone();

					delete FigList[i];
					delete FigList[j];

					FigList[i] = y;
					FigList[j] = x;

					FigList[i]->SetSelected(true);
					FigList[j]->SetSelected(true);

					return;
				}
			}
		}
		
	}
}

bool ApplicationManager::GetOneSelectedFig(CFigure*& fig) const
{
	int found = 0;

	for (int i = 0; i < FigCount; i++) {

		if (FigList[i]->IsSelected()==true) {

			if (found == 0) 
				fig = FigList[i];
			
			found++;

			if (found > 1)
				break;
		}
	}
	if (found == 1)
		return true;

	else
		return false;
}


//////////////////////////////////////////////////////////////////////////////////////
void ApplicationManager::UnSelectAll()
{
	for (int i = FigCount - 1; i >= 0; i--)
	{
		if (FigList[i]->IsSelected() && FigList[i]!=nullptr)
		{
			FigList[i]->ChngDrawClr(pOut->getCrntDrawColor());
			FigList[i]->SetSelected(false);
		}
	}
}
//////////////////////////////////////////////////////////////////////////////////////

//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{	
	for(int i=0; i<FigCount; i++)
		FigList[i]->Draw(pOut);		//Call Draw function (virtual member fn)
}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the input
Input *ApplicationManager::GetInput() const
{	return pIn; }
//Return a pointer to the output
Output *ApplicationManager::GetOutput() const
{	return pOut; }
////////////////////////////////////////////////////////////////////////////////////
//Destructor
ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<FigCount; i++)
		delete FigList[i];
	delete pIn;
	delete pOut;
	
}

