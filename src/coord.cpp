#include"coord.h"

coord::coord()
	: y(0), x(0)
{

}
coord::coord(int initY, int initX)
	: y(initY), x(initX)
{

}
int coord::getY()
{
	return y;
}
int coord::getX()
{
	return x;
}
void coord::setY(int dest)
{
	y = dest;
}
void coord::setX(int dest)
{
	x = dest;
}
void coord::goOneSpace(int direction)
{
	if (direction == LEFT)
	{
		x -= 1;
	}
	else if (direction == RIGHT)
	{
		x += 1;
	}
	else if (direction == UP)
	{
		y -= 1;
	}
	else if (direction == DOWN)
	{
		y += 1;
	}
}