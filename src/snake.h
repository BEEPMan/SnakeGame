#pragma once

#include<queue>
#include"coord.h"

using namespace std;

class snake
{
public:
	snake();
	snake(coord startPos, int maxSize);
	coord getHeadPosition();
	coord getTailPosition();
	int getHeadDirection();
	int getLength();
	void move(bool isEat);
	void Rotate(int direction);
private:
	coord headPos;
	int heading;
	queue<coord> bodyPos;
	int length;
};