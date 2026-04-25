#include "CTriangle.h"

CTriangle::CTriangle(Point P1, Point P2,Point P3, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	Corner3 = P3;
}

void CTriangle::Draw(Output* pOut) const
{
	//Call Output::DrawTri to draw a triangle on the screen	
	pOut->DrawTri(Corner1, Corner2, Corner3, FigGfxInfo, Selected);
}

double triangleArea(Point p1, Point p2, Point p3)
{
	return((abs(p1.x * (p2.y - p3.y) + p2.x * (p3.y - p1.y) + p3.x * (p1.y - p2.y))) / 2);
}

bool CTriangle::IsInside(int x, int y) const
{
	Point p = { x,y };
	double A1 = triangleArea(p, Corner1, Corner2);
	double A2 = triangleArea(p, Corner2, Corner3);
	double A3 = triangleArea(p, Corner1, Corner3);

	double SumArea = A1 + A2 + A3;

	return(SumArea == triangleArea(Corner1, Corner2, Corner3));

}

void CTriangle::PrintInfo(Output* pOut) const
{

	pOut->PrintMessage("Figure is triangle || Id: " + to_string(ID) + " || Corner 1: (" + to_string(Corner1.x) + "," + to_string(Corner1.y) + ") || Corner 2: (" + to_string(Corner2.x) + "," + to_string(Corner2.y) + ") || Corner 3: (" + to_string(Corner3.x) + "," + to_string(Corner3.y) + ") || Color: " + colorToString(pOut->getCrntDrawColor()));

}
Point CTriangle::CalcCenter() 
{
	Point C;

	C.x = (Corner1.x + Corner2.x + Corner3.x) / 3;
	C.y = (Corner1.y + Corner2.y + Corner3.y) / 3;
	return C;
}

void CTriangle::Move(int dx, int dy)
{
	Corner1.x = Corner1.x + dx;
	Corner2.x = Corner2.x + dx;
	Corner3.x = Corner3.x + dx;
	Corner1.y = Corner1.y + dy;
	Corner2.y = Corner2.y + dy;
	Corner3.y = Corner3.y + dy;
}

CFigure* CTriangle::Clone() const
{
	return new CTriangle(*this);
}

void CTriangle::Rotate(Output* pOut, CFigure*& fig)
{
	const Point m=fig->CalcCenter();

	int dx1, dy1, dx2, dy2, dx3, dy3;

	dx1 = Corner1.x - m.x;
	dy1 = Corner1.y - m.y;

	dx2 = Corner2.x - m.x;
	dy2 = Corner2.y - m.y;
	
	dx3 = Corner3.x - m.x;
	dy3 = Corner3.y - m.y;

	int x1, y1, x2, y2, x3, y3;

	x1 = m.x + dy1;
	y1 = m.y - dx1;

	x2 = m.x + dy2;
	y2 = m.y - dx2;

	x3 = m.x + dy3;
	y3 = m.y - dx3;

	Corner1.x = x1;
	Corner1.y = y1;

	Corner2.x = x2;
	Corner2.y = y2;

	Corner3.x = x3;
	Corner3.y = y3;

	pOut->ClearDrawArea();
}
