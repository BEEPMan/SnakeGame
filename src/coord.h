#pragma once

#define LEFT 11
#define RIGHT 12
#define UP 13
#define DOWN 14

class coord
{
public:
	coord();
	coord(int initX, int initY);
	int getX();
	int getY();
	void setX(int dest);
	void setY(int dest);
	void goOneSpace(int direction);
private:
	int x;
	int y;
};