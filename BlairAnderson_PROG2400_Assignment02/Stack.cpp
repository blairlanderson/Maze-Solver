#include "Stack.h"

using namespace std;

Stack::Stack()
{
	size = 0;
	coordsArray = new Coords[size];
}

//add new element to the stack
void Stack::push(Coords loc)
{
	size++;

	//vector method is this cheating??
	coordArray.push_back(loc);

	//regular array method
	/*
	Coords *temp = new Coords[size];
	temp = coordsArray;
	//memcpy(temp, coordsArray, sizeof(Coords));
	delete coordsArray;
	coordsArray = temp;
	coordsArray[size - 1] = loc;
	*/
}

//remove an element off the stack
void Stack::pop()
{
	size--;

	//vector method
	coordArray.pop_back();
}

//get top element from the stack
Coords Stack::getTop()
{
	Coords top;
	
	//vector method
	top = coordArray.back();
	return top;
}

//return size of stack
int Stack::getSize()
{
	return size;
}

//determine of stack is empty
bool Stack::isEmpty()
{
	//vector method
	if (coordArray.empty() == true)
		return true;
	else
		return false;
}