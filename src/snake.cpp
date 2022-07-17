#include"snake.h"
#include"coord.h"

snake::snake()
	: headPos(1, 1), heading(0), length(1)
{
	tailPos = new coord[3];
}
snake::snake(coord startPos, int maxSize)
	: headPos(startPos.getY(), startPos.getX()), heading(0), length(1)
{
	tailPos = new coord[maxSize];
}
coord snake::getHeadPosition()
{
	return headPos;
}
int snake::getHeadDirection()
{
	return heading;
}
int snake::getLength()
{
	return length;
}
void snake::move(bool isEat)
{
	if (length > 1)
	{
		if (isEat)
		{
			tailPos[length].setY(headPos.getY());
			tailPos[length].setX(headPos.getX());
			length++;
		}
		else
		{
			for (int i = 1; i < length - 1; i++)
			{
				tailPos[i].setY(tailPos[i + 1].getY());
				tailPos[i].setX(tailPos[i + 1].getX());
			}
			tailPos[length - 1].setY(headPos.getY());
			tailPos[length - 1].setX(headPos.getX());
		}
	}
	else
	{
		if (isEat)
		{
			tailPos[length].setY(headPos.getY());
			tailPos[length].setX(headPos.getX());
			length++;
		}
	}
	headPos.goOneSpace(heading);
}
void snake::Rotate(int direction)
{
	heading = direction;
}