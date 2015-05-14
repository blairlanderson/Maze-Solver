#pragma once
#include "Stack.h"
#include "Maze.h"

using namespace std;

//class to run through a maze text file and find the solution
class MazeRunner
{
private:
	Stack stack;
public:
	//MazeRunner();

	void runMaze(Maze *maze);
	bool checkMove(int x, int y, Maze *maze);
	void makeMove(int x, int y, Maze *maze);
	
};

