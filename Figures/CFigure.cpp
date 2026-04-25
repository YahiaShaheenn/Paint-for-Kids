#include "CFigure.h"

CFigure::CFigure(GfxInfo FigureGfxInfo)
{ 
	FigGfxInfo = FigureGfxInfo;	//Default status is non-filled.
	Selected = false;


	
}

void CFigure::SetSelected(bool s)
{	Selected = s; }

bool CFigure::IsSelected() const
{	return Selected; }

void CFigure::ChngDrawClr(color Dclr)
{	FigGfxInfo.DrawClr = Dclr; }

void CFigure::ChngFillClr(color Fclr)
{	
	FigGfxInfo.isFilled = true;
	FigGfxInfo.FillClr = Fclr; 
}

string CFigure::colorToString(color clr)const
{
	if (clr == RED)
		return ("Red");
	else if (clr == ORANGE)
		return ("Orange");
	else if (clr == YELLOW)
		return ("Yellow");
	else if (clr == GREEN)
		return ("Green");
	else if (clr == BLUE)
		return ("Blue");
	else if (clr == PURPLE)
		return ("Violet");
	else if (clr == BLACK)
		return ("Black");
	else if (clr == BROWN)
		return ("Brown");
	else if (clr == LAVENDER)
		return ("Lavender");
}

color CFigure::stringToColor(string clr)
{
	if (clr == "r" || clr == "R")
		return (RED);
	else if (clr == "o" || clr == "O")
		return (ORANGE);
	else if (clr == "y" || clr == "Y")
		return (YELLOW);
	else if (clr == "g" || clr == "G")
		return (GREEN);
	else if (clr == "g" || clr == "B")
		return (BLUE);
	else if (clr == "p" || clr == "P")
		return (PURPLE);
	else if (clr == "BL" || clr == "bl" || clr=="bL" || clr=="Bl")
		return (BLACK);
	else if (clr == "BR" || clr == "br" || clr == "bR" || clr == "Br")
		return (BROWN);
	else if (clr == "l" || clr == "L")
		return (LAVENDER);
}

void CFigure::setID(int id)
{
	ID = id;
}

