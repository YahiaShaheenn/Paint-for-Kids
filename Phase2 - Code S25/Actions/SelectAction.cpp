#include "SelectAction.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

SelectAction::SelectAction(ApplicationManager* pApp) :Action(pApp)
{}

void SelectAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Click a point inside a figure to select/unselect, click a tool bar item to stop selecting");

	pIn->GetPointClicked(P1.x, P1.y);

	pOut->ClearStatusBar();

}

void SelectAction::Execute()
{
	

	Output* pOut = pManager->GetOutput();

	CFigure* s = nullptr;
	
	
		ReadActionParameters();

		s = pManager->GetFigure(P1.x, P1.y);

		if (s != nullptr)
		{
			if (s->IsSelected() == false)
			{
				s->ChngDrawClr(MAGENTA);
				s->SetSelected(true);
			}
			else
			{
				s->ChngDrawClr(pOut->getCrntDrawColor());
				s->SetSelected(false);
			}
		}
		else
		{
			pManager->UnSelectAll();
		}
}



