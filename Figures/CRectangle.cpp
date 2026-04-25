#include "CRectangle.h"

CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
}
	

void CRectangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawRect(Corner1, Corner2, FigGfxInfo, Selected);
}

bool CRectangle::IsInside(int x, int y) const
{
	if (Corner1.x < Corner2.x && Corner1.y < Corner2.y) {
		if (x >= Corner1.x && x <= Corner2.x && y >= Corner1.y && y <= Corner2.y)
			return(true);
		else
			return(false);
	}
	else if (Corner1.x > Corner2.x && Corner1.y < Corner2.y)
	{
		if (x <= Corner1.x && x >= Corner2.x && y >= Corner1.y && y <= Corner2.y)
			return(true);
		else
			return(false);
	}

	else if (Corner1.x < Corner2.x && Corner1.y > Corner2.y)
	{
		if (x <= Corner1.x && x >= Corner2.x && y <= Corner1.y && y >= Corner2.y)
			return(true);
		else
			return(false);
	}

	else
	{
		if (x >= Corner1.x && x <= Corner2.x && y <= Corner1.y && y >= Corner2.y)
			return(true);
		else
			return(false);
	}
}

void CRectangle::PrintInfo(Output* pOut) const
{
	double w = abs(Corner1.x - Corner2.x);
	double h = abs(Corner1.y - Corner2.y);

	pOut->PrintMessage("Figure is rectangle || Id: " + to_string(ID) + " || Corner 1: (" + to_string(Corner1.x) + "," + to_string(Corner1.y) + ") || Corner 2: (" + to_string(Corner2.x) + "," + to_string(Corner2.y) + ") || Width: " + to_string(w) + " || Height: " + to_string(h) + " || Color: " + colorToString(pOut->getCrntDrawColor()));
}
Point CRectangle::CalcCenter()
{
	Point C;

	C.x = (Corner1.x + Corner2.x) / 2;
	C.y = (Corner1.y + Corner2.y) / 2;
	return C;
}

void CRectangle::Move(int dx, int dy) 
{
	Corner1.x = Corner1.x + dx;
	Corner2.x = Corner2.x + dx;
	Corner1.y = Corner1.y + dy;
	Corner2.y = Corner2.y + dy;
}

CFigure* CRectangle::Clone() const
{
	return new CRectangle(*this);
}

void CRectangle::Rotate(Output* pOut,CFigure*&fig)
{
	const Point m = fig->CalcCenter();

	int dx1, dy1, dx2, dy2;

	dx1 = Corner1.x - m.x;
	dy1 = Corner1.y - m.y;

	dx2 = Corner2.x - m.x;
	dy2 = Corner2.y - m.y;

	int x1, y1, x2, y2;

	x1 = m.x + dy1;
	y1 = m.y - dx1;

	x2 = m.x + dy2;
	y2 = m.y - dx2;

	Corner1.x = x1;
	Corner1.y = y1;

	Corner2.x = x2;
	Corner2.y = y2;

	pOut->ClearDrawArea();
}
