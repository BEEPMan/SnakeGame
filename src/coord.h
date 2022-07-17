#pragma once

#define LEFT 11
#define RIGHT 12
#define UP 13
#define DOWN 14

class coord
{
public:
	coord();
	coord(int initY, int initX);
	int getY();
	int getX();
	void setY(int dest);
	void setX(int dest);
	void goOneSpace(int direction);
private:
	int y;
	int x;
};