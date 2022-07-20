#include"coord.h"

Coord::Coord()
	: mX(0), mY(0)
{

}

Coord::Coord(int x, int y)
	: mX(x), mY(y)
{

}

int Coord::getX()
{
	return mX;
}

int Coord::getY()
{
	return mY;
}

void Coord::setX(int x)
{
	mX = x;
}

void Coord::setY(int y)
{
	mY = y;
}

void Coord::goOneSpace(int direction)
{
	if (direction == LEFT)
	{
		mY -= 1;
	}
	else if (direction == RIGHT)
	{
		mY += 1;
	}
	else if (direction == UP)
	{
		mX -= 1;
	}
	else if (direction == DOWN)
	{
		mX += 1;
	}
}