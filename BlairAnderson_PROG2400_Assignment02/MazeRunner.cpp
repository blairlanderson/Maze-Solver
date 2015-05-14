#include "MazeRunner.h"

using namespace std;

void MazeRunner::runMaze(Maze *maze)
{
	//put the start of the maze at the bottom of the stack
	stack.push(maze->getEntrance());
	maze->setMarker(stack.getTop().getX(), stack.getTop().getY());

	//run through the maze
	while (stack.getTop().getY() != maze->getCols() - 1)
	{
		if (checkMove(stack.getTop().getX(), stack.getTop().getY(), maze) == true)
		{
			//make the move
			makeMove(stack.getTop().getX(), stack.getTop().getY(), maze);

			//set a trailblazer marker 
			maze->setMarker(stack.getTop().getX(), stack.getTop().getY());
		}
		else
		{
			stack.pop();
		}
	}//end while

	//solve maze with stack
	maze->escapeMaze(&stack);


}

bool MazeRunner::checkMove(int x, int y, Maze *maze)
{
	//check RIGHT (->) for empty space
	if (x < maze->getRows() && maze->getMarker((x + 1), y) == ' ')
		return true;
	//check DOWN (V) for empty space
	else if (y < maze->getCols() && maze->getMarker(x, (y + 1)) == ' ')
		return true;
	//check LEFT (<-) for empty space
	else if(x > 0 && maze->getMarker((x - 1), y) == ' ')
		return true;
	//check UP (^) for empty space
	else if (y > 0 && maze->getMarker(x, (y - 1)) == ' ')
		return true;
	//no mas
	else
		return false;
}

void MazeRunner::makeMove(int x, int y, Maze *maze)
{
	//check RIGHT (->) for empty space
	if (x < maze->getRows() && maze->getMarker((x + 1), y) == ' ')
		stack.push(Coords((x + 1), y));
	//check DOWN (V) for empty space
	else if (y < maze->getCols() && maze->getMarker(x, (y + 1)) == ' ')
		stack.push(Coords(x, (y + 1)));
	//check LEFT (<-) for empty space
	else if (x > 0 && maze->getMarker((x - 1), y) == ' ')
		stack.push(Coords((x - 1), y));
	//check UP (^) for empty space
	else if (y > 0 && maze->getMarker(x, (y - 1)) == ' ')
		stack.push(Coords(x, (y - 1)));
	//no mas		
}
