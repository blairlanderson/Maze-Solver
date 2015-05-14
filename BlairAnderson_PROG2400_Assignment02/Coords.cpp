#include "Coords.h"

using namespace std;

//default coords constructor
Coords::Coords()
{
	this->x = 0;
	this->y = 0;
}

//constructor when given x,y values
Coords::Coords(int x, int y)
{
	this->x = x;
	this->y = y;
}

//return the x value
int Coords::getX()
{
	return this->x;
}

//return the y value
int Coords::getY()
{
	return this->y;
}
