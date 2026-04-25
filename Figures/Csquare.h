#ifndef CSQU_H
#define CSQU_H

#include "CFigure.h"

class Csquare : public CFigure
{
private:
	Point Center;

public:
	Csquare(Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual bool IsInside(int x, int y) const;
	virtual void PrintInfo(Output* pOut)const;
	virtual Point CalcCenter();
	virtual void Move(int dx, int dy);
	virtual CFigure* Clone() const;
	virtual void Rotate(Output* pOut, CFigure*& fig);


};

#endif