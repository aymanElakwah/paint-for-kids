#include "CTriangle.h"
#include "..\Functions.h"

CTriangle::CTriangle()
{
}

CTriangle::CTriangle(Point P1, Point P2, Point P3, GfxInfo FigureGfxInfo) : CFigure(FigureGfxInfo)
{
	Vertix1 = P1;
	Vertix2 = P2;
	Vertix3 = P3;
}

void CTriangle::Draw(Output* pOut) const
{
	if (Visible)
		pOut->DrawTriangle(Vertix1, Vertix2, Vertix3, FigGfxInfo, Selected);
}

bool CTriangle::IsInside(Point P)
{
	if (!Visible)
		return false;
	return (SameSide(P, Vertix3, Vertix1, Vertix2) && SameSide(P, Vertix1, Vertix2, Vertix3) && SameSide(P, Vertix2, Vertix1, Vertix3));
}

void CTriangle::Save(ofstream & OutFile) const
{
	OutFile << "TRIANG\t" << ID << "\t"
		<< Vertix1.x << "\t" << Vertix1.y << "\t" << Vertix2.x << "\t" << Vertix2.y << "\t" << Vertix3.x << "\t" << Vertix3.y << "\t"
		<< getColorNumber(FigGfxInfo.DrawClr) << "\t"
		<< (FigGfxInfo.isFilled ? getColorNumber(FigGfxInfo.FillClr) : -1) << endl;
}

void CTriangle::Load(ifstream & Infile)
{
	Infile >> ID >> Vertix1.x >> Vertix1.y >> Vertix2.x >> Vertix2.y >> Vertix3.x >> Vertix3.y;
	int color;
	Infile >> color;
	FigGfxInfo.DrawClr = getColorByNumber(color);
	Infile >> color;
	if (color == -1) {
		FigGfxInfo.isFilled = false;
	}
	else {
		FigGfxInfo.isFilled = true;
		FigGfxInfo.FillClr = getColorByNumber(color);
	}
	Infile.ignore();
}

void CTriangle::PrintInfo(Output* pOut)
{
	string strID = to_string(ID);
	string strVertix1 = "(" + to_string(Vertix1.x) + "," + to_string(Vertix1.y) + ")";
	string strVertix2 = "(" + to_string(Vertix2.x) + "," + to_string(Vertix2.y) + ")";
	string strVertix3 = "(" + to_string(Vertix3.x) + "," + to_string(Vertix3.y) + ")";

	int Side1 = rint(sqrt(pow(Vertix1.x - Vertix2.x, 2) + pow(Vertix1.y - Vertix2.y, 2)));
	int Side2 = rint(sqrt(pow(Vertix3.x - Vertix2.x, 2) + pow(Vertix3.y - Vertix2.y, 2)));
	int Side3 = rint(sqrt(pow(Vertix1.x - Vertix3.x, 2) + pow(Vertix1.y - Vertix3.y, 2)));
	string strSide1 = to_string(Side1);
	string strSide2 = to_string(Side2);
	string strSide3 = to_string(Side3);

	string FillColor = FigGfxInfo.isFilled ? FigGfxInfo.FillClr.getName() : "Not Filled";

	pOut->PrintMessage("Triangle  |  ID : " + to_string(ID) + "  |  Vertices : " + strVertix1 + ", " + strVertix2 + ", " + strVertix3
		+ "  |  Dimensions : " + strSide1 + " × " + strSide2 + " × " + strSide3
		+ "  |  Draw Color : " + FigGfxInfo.DrawClr.getName() + ", Fill Color : " + FillColor);
}

CFigure* CTriangle::CopyFigure()
{
	CFigure* Triangle=new CTriangle(Vertix1,Vertix2,Vertix3,FigGfxInfo);
	return Triangle;
}

Point CTriangle::GetCenter()
{
	Point MiddlePoint;
	MiddlePoint=Vertix1+Vertix2;
	MiddlePoint+=Vertix3;
	MiddlePoint/=3;
	return MiddlePoint;
}

void CTriangle::Move(Point NewCenter)
{
	Vertix1+=NewCenter;
	Vertix2+=NewCenter;
	Vertix3+=NewCenter;
}

string CTriangle::getName() const
{
	return "TRIANGLE";
}

void CTriangle::rotate()
{
	Point center = GetCenter();
	Vertix1.rotate(center);
	Vertix2.rotate(center);
	Vertix3.rotate(center);
}

bool CTriangle::isSame(CFigure* figChoose) const
{
	return (dynamic_cast<CTriangle*>(figChoose));
}
