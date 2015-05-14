#pragma once

//custom class to hold an x,y coordinate location in the maze
class Coords
{
private:
	int x;
	int y;
public:
	Coords();
	Coords(int x, int y);
	
	int getX();
	int getY();
};

