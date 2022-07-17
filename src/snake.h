#pragma once

#include<vector>
#include"coord.h"

using namespace std;

class snake
{
public:
	snake();
	snake(coord startPos, int maxSize);
	coord getHeadPosition();
	int getHeadDirection();
	int getLength();
	void move(bool isEat);
	void Rotate(int direction);
private:
	coord headPos;
	int heading;
	coord* tailPos;
	int length;
};