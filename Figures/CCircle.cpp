#include "CCircle.h"

CCircle::CCircle(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Center = P1;
	Circum = P2;

}

void CCircle::Draw(Output* pOut) const
{
	//Call Output::DrawCircle to draw a square on the screen	
	pOut->DrawCirc(Center, Circum, FigGfxInfo, Selected);
}
bool CCircle::IsInside(int x, int y) const
{
	int R = sqrt(pow((Center.x - Circum.x), 2) + pow((Center.y - Circum.y), 2));

	return((pow(R,2)) >= pow((x - Center.x), 2) + pow((y - Center.y), 2));
}

void CCircle::PrintInfo(Output* pOut) const
{
	double R= sqrt(pow((Center.x - Circum.x), 2) + pow((Center.y - Circum.y), 2));

	pOut->PrintMessage("Figure is circle || Id: " + to_string(ID) + " || Center : (" + to_string(Center.x) + "," + to_string(Center.y) + ") || Radius: " + to_string(R)  + " || Color: " + colorToString(pOut->getCrntDrawColor()));

}
Point CCircle::CalcCenter()
{
	return Center;
}

void CCircle::Move(int dx, int dy)
{
	Center.x = Center.x + dx;
	Center.y = Center.y + dy;
	Circum.x = Circum.x + dx;
	Circum.y = Circum.y + dy;
}

CFigure* CCircle::Clone() const
{
	return new CCircle(*this);
}

void CCircle::Rotate(Output* pOut, CFigure*& fig)
{
	pOut->PrintMessage("Cannot rotate circle, please select a different figure");
}
