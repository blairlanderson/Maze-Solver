#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Coords.h"

using namespace std;

//Custom created stack class
class Stack
{
private:
	int size;
	vector<Coords> coordArray;
	Coords* coordsArray;

public:
	Stack();

	void push(int x, int y);
	void push(Coords loc);
	void pop();
	
	Coords getTop();
	int getSize();
	bool isEmpty();


};
