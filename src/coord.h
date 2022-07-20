#pragma once

#define LEFT 11
#define RIGHT 12
#define UP 13
#define DOWN 14

class Coord
{
public:
	Coord();
	Coord(int x, int y);
	int getX();
	int getY();
	void setX(int x);
	void setY(int y);
	void goOneSpace(int direction);
private:
	int mX;
	int mY;
};