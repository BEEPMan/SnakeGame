#include"snake.h"
#include"coord.h"

snake::snake()
	: headPos(1, 1), heading(0), length(1)
{
}
snake::snake(coord startPos, int maxSize)
	: headPos(startPos.getX(), startPos.getY()), heading(0), length(1)
{
}
coord snake::getHeadPosition()
{
	return headPos;
}
coord snake::getTailPosition()
{
	return bodyPos.front();
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
			bodyPos.push(headPos);
			length++;
		}
		else
		{
			bodyPos.push(headPos);
			bodyPos.pop();
		}
	}
	else
	{
		if (isEat)
		{
			bodyPos.push(headPos);
			length++;
		}
	}
	headPos.goOneSpace(heading);
}
void snake::Rotate(int direction)
{
	heading = direction;
}