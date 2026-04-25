#include "Csquare.h"

Csquare::Csquare(Point P1, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Center = P1;
	
}

void Csquare::Draw(Output* pOut) const
{
	//Call Output::DrawSquare to draw a square on the screen	
	pOut->DrawSquare(Center, FigGfxInfo, Selected);
}

bool Csquare::IsInside(int x, int y) const
{
	const int R = 150;
	const double halfL = R / (sqrt(2));

	return(abs(x - Center.x) <= halfL && abs(y - Center.y) <= halfL);
}

void Csquare::PrintInfo(Output* pOut) const
{
	double halfL = 75 * sqrt(2);
	Point Corner1, Corner2;
	Corner1.x = Center.x - halfL;
	Corner1.y = Center.y - halfL;
	Corner2.x = Center.x - halfL;
	Corner2.y = Center.y - halfL;

	pOut->PrintMessage("Figure is square || Id: " + to_string(ID) + " || Corner 1: (" + to_string(Corner1.x) + "," + to_string(Corner1.y) + ") || Corner 2: (" + to_string(Corner2.x) + "," + to_string(Corner2.y) + ") || Center: (" + to_string(Center.x) + "," + to_string(Center.y) + ") || Side Length: " + to_string(halfL*2) + " || Color: " + colorToString(pOut->getCrntDrawColor()));
}
Point Csquare::CalcCenter()
{
	return Center;
}

void Csquare::Move(int dx, int dy)
{
	Center.x = Center.x + dx;
	Center.y = Center.y + dy;
}

CFigure* Csquare::Clone() const
{
	return new Csquare(*this);
}

void Csquare::Rotate(Output* pOut, CFigure*& fig)
{
	pOut->PrintMessage("Cannot rotate square, please select a different figure");
}
