#include"snake.h"

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

void snake::move(map& table, int& colliedObj)
{
	coord collCheck = headPos;
	collCheck.goOneSpace(heading);
	int collObj = table.getTile(collCheck.getX(), collCheck.getY());
	colliedObj = collObj;
	if (collObj == BODY || collObj == WALL)
	{
		return;
	}
	else if (collObj == APPLE)
	{
		bodyPos.push(headPos);
		table.setTile(headPos.getX(), headPos.getY(), BODY);
		length++;
		table.placeApple();
	}
	else
	{
		if (length > 1)
		{
			table.setTile(headPos.getX(), headPos.getY(), BODY);
			bodyPos.push(headPos);
			table.setTile(bodyPos.front().getX(), bodyPos.front().getY(), FLOOR);
			bodyPos.pop();
		}
		else
		{
			table.setTile(headPos.getX(), headPos.getY(), FLOOR);
		}
	}
	headPos.goOneSpace(heading);
	table.setTile(headPos.getX(), headPos.getY(), HEAD);
}

void snake::rotate(int direction)
{
	heading = direction;
}