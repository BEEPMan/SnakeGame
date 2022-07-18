#pragma once

#include<queue>
#include"coord.h"
#include"map.h"

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
	void move(map& table, int& colliedObj);
	void rotate(int direction);
private:
	coord headPos;
	int heading;
	queue<coord> bodyPos;
	int length;
};