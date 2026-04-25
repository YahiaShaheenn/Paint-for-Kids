#include "RotateAction.h"
#include "SelectAction.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

RotateAction::RotateAction(ApplicationManager* pApp) :Action(pApp)
{
}

void RotateAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
}

void RotateAction::Execute()
{
	CFigure* fig;

	Output* pOut = pManager->GetOutput();

	if (pManager->GetOneSelectedFig(fig) == true) {

		fig->Rotate(pOut,fig);
	}
	else
		pOut->PrintMessage("Cannot rotate, please select one figure");
}
