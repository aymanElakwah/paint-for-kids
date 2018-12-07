#pragma once
#include "CFigure.h"

class CTriangle : public CFigure
{
private:
	Point Vertix1;
	Point Vertix2;
	Point Vertix3;
public:
	CTriangle();
	CTriangle(Point, Point, Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual bool IsInside(Point P);
	virtual void Save(ofstream &OutFile) const;
	virtual void Load(ifstream &Infile);
	virtual void PrintInfo(Output* pOut);
	virtual CFigure*CopyFigure();
	virtual Point GetCenter();
	virtual void Move(Point);
	virtual string getName() const;
	virtual void rotate();
	virtual bool isSame(CFigure* figChoose) const;
};
