#include "Functions.h"

Point Vector(Point P1, Point P2)
{
	Point V;
	V.x = P2.x - P1.x;
	V.y = P2.y - P1.y;
	return V;
}

int CrossProduct(Point V1, Point V2)
{
	return (V1.x*V2.y - V1.y*V2.x);
}

bool SameSide(Point P1, Point P2, Point A, Point B)
{
	Point V1 = Vector(A, P1);
	Point V2 = Vector(A, P2);
	Point Vb = Vector(A, B);
	int CP1 = CrossProduct(V1, Vb);
	int CP2 = CrossProduct(V2, Vb);
	return ((CP1 >= 0 && CP2 >= 0) || (CP1 <= 0 && CP2 <= 0));
}