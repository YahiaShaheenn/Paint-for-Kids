#include "CHexagon.h"

CHexagon::CHexagon (Point P1, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Corner1 = P1;

}

void CHexagon::Draw(Output* pOut) const
{
	//Call Output::DrawHex to draw a square on the screen	
	pOut->DrawHex(Corner1, FigGfxInfo, Selected);
}

bool CHexagon::IsInside(int x, int y) const
{
	double distX=abs(x-Corner1.x);
	double distY=abs(y-Corner1.y);
	const int R = 150;

	return(distX <= R && distY <= sqrt(3) * R / 2 && sqrt(3) * distX + distY <= sqrt(3) * R);
}

void CHexagon::PrintInfo(Output* pOut) const
{
	pOut->PrintMessage("Figure is hexagon || Id: " + to_string(ID) + " || Center : (" + to_string(Corner1.x) + "," + to_string(Corner1.y) + ") || Side length: 150 || Color: " + colorToString(pOut->getCrntDrawColor()));

}
Point CHexagon::CalcCenter()
{
	return Corner1;
}

void CHexagon::Move(int dx, int dy)
{
	Corner1.x = Corner1.x + dx;
	Corner1.y = Corner1.y + dy;
}

CFigure* CHexagon::Clone() const
{
	return new CHexagon(*this);
}

void CHexagon::Rotate(Output* pOut,CFigure*& fig)
{

}


