#include"coord.h"

coord::coord()
	: x(0), y(0)
{

}
coord::coord(int initX, int initY)
	: x(initY), y(initX)
{

}
int coord::getX()
{
	return x;
}
int coord::getY()
{
	return y;
}
void coord::setX(int dest)
{
	x = dest;
}
void coord::setY(int dest)
{
	y = dest;
}
void coord::goOneSpace(int direction)
{
	if (direction == LEFT)
	{
		y -= 1;
	}
	else if (direction == RIGHT)
	{
		y += 1;
	}
	else if (direction == UP)
	{
		x -= 1;
	}
	else if (direction == DOWN)
	{
		x += 1;
	}
}