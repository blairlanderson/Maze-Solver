#pragma once
#include <fstream>
#include "Stack.h"

using namespace std;

//class for holding and interacting with a rectangular maze 
//with unknown dimensions in a text file 
class Maze
{
private:
	int rows;
	int cols;
	const Coords entrance;
	char **maze;
	string *sMaze;
	char **completedMaze;
	string *sCompletedMaze;

public:
	Maze(Coords entrance, string pathIn);

	void setMarker(int x, int y);
	char getMarker(int x, int y);
	
	int getRows();
	int getCols();
	const Coords getEntrance();

	char getCompletedMazeAtLocation(int x, int y);
	void escapeMaze(Stack *stack);
	void saveMaze(string inputFile, string outputFile);
};