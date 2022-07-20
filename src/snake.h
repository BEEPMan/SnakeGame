#pragma once

#include<queue>
#include"coord.h"
#include"gameBoard.h"

using namespace std;

class Snake
{
public:
	Snake();
	Snake(Coord startPos, int maxSize);
	Coord getHeadPosition();
	Coord getTailPosition();
	int getHeadDirection();
	int getLength();
	void move(GameBoard& table, int& colliedObj);
	void rotate(int direction);
private:
	Coord mHeadPos;
	int mHeading;
	queue<Coord> mBodyPos;
	int mLength;
};