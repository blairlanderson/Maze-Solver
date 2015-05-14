#include "Maze.h"
#include "MazeRunner.h"

#include <conio.h>
//#include <iostream>
//#include <string>
using namespace std;

void print(Maze *maze);
void debugPrint(Maze *maze);

int main()
{
	string fileNameIn;
	string fileNameOut;
	Coords entrance(1, 0);

	//Get Input maze filename
	cout << "Enter file name of text maze to solve: ";
	getline(cin, fileNameIn);

	cout << endl;

	//Create Maze Obj = Read maze into it
	Maze maze(entrance, fileNameIn);
	Maze *mazePtr = &maze;
	
	/*
	//Print the unsolved Maze
	debugPrint(mazePtr);
	cout << endl << endl;
	*/
	
	//Solve maze
	MazeRunner runner;
	runner.runMaze(mazePtr);
	
	//print solved maze to console
	print(mazePtr);

	//get filename for solved maze
	cout << endl << "Enter file name to save solved maze to: ";
	getline(cin, fileNameOut);

	//save file
	maze.saveMaze(fileNameIn, fileNameOut);

	cout << "Saved.." << endl;

	

	_getch();

	return 0;
}

void print(Maze *maze)
{
	for (int x = 0; x < maze->getRows(); x++)
	{
		for (int y = 0; y < maze->getCols(); y++)
		{
			cout << maze->getCompletedMazeAtLocation(x, y);
		}
		cout << endl;
	}
}

void debugPrint(Maze *maze)
{
	for (int x = 0; x < maze->getRows(); x++)
	{
		for (int y = 0; y < maze->getCols(); y++)
		{
			cout << maze->getMarker(x, y);
		}
		cout << endl;
	}
}