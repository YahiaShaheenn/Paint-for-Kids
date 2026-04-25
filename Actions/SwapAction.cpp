#include "SwapAction.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

SwapAction::SwapAction(ApplicationManager* pApp) :Action(pApp)
{

}

void SwapAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
}

void SwapAction::Execute()
{
	CFigure* fig1;
	CFigure* fig2;

	Output* pOut = pManager->GetOutput();

	if (pManager->GetTwoSelectedFigures(fig1, fig2) == true) {

		Point m = fig1->CalcCenter();
		Point n = fig2->CalcCenter();

		int dx = m.x - n.x;
		int dy = m.y - n.y;

		

		if (pManager->GetTwoSelectedFigures(fig1, fig2) == true) {
			fig1->Move(-dx, -dy);
			fig2->Move(dx, dy);

			pManager->SwapInFigList();

			pOut->ClearDrawArea();
		}



	}
	else
		pOut->PrintMessage("Cannot swap, please choose two figures only");
}
