#define _CRT_SECURE_NO_WARNINGS
#include "Maze.h"

//maze constructor, taking in coords of entrance, and the filename of the maze
Maze::Maze(Coords entrance, string pathIn)
{
	ifstream mazeIn;
	char lineIn[1024];
	
	mazeIn.open(pathIn, std::ifstream::in);

	while (!mazeIn.eof())
	{
		mazeIn.getline(lineIn, 1024);
		rows++;
	}

	cols = strlen(lineIn);

	// Returning to the beginning of the file. 
	mazeIn.clear();
	mazeIn.seekg(0, ios::beg);

	// Allocating memory for the elements.
	maze = new char*[rows];
	completedMaze = new char*[rows];

	for (int i = 0; i < rows; i++)
	{
		maze[i] = new char[cols];
		completedMaze[i] = new char[cols];
	}

	// Writing the file to the arrays.
	int x = 0;
	while (!mazeIn.eof())
	{
		mazeIn.getline(lineIn, 1024);
		strcpy(completedMaze[x], lineIn);
		strcpy(maze[x], lineIn);
		
		x++;
	}

	mazeIn.close();
}

//set position within maze
void Maze::setMarker(int x, int y)
{
	maze[x][y] = '#';
}

//learn what char is at a maze position
char Maze::getMarker(int x, int y)
{
	return maze[x][y];
}

int Maze::getRows()
{
	return this->rows;
}

int Maze::getCols()
{
	return this->cols;
}

const Coords Maze::getEntrance()
{
	return entrance;
}

//used for creating the solved version of the maze
char Maze::getCompletedMazeAtLocation(int x, int y)
{
	return completedMaze[x][y];
}

//use the constructed stack to run through the maze
void Maze::escapeMaze(Stack *stack)
{
	int moves = stack->getSize();

	for (int i = 0; i < moves; i++)
	{
		completedMaze[stack->getTop().getX()][stack->getTop().getY()] = '#';
		stack->pop();
	}
}

//function for saving new txt file
void Maze::saveMaze(string fileNameIn, string fileNameOut)
{
	ofstream savedMaze;

	savedMaze.open(fileNameOut);
	savedMaze << "Solved Version of: " << fileNameIn << endl << endl << endl;

	for (int i = 0; i < rows; i++)
	{
		savedMaze << completedMaze[i] << endl;
	}

	savedMaze.close();
}