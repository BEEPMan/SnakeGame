#include"Snake.h"

Snake::Snake()
	: mHeadPos(1, 1), mHeading(0), mLength(1)
{
}

Snake::Snake(Coord startPos, int maxSize)
	: mHeadPos(startPos.getX(), startPos.getY()), mHeading(0), mLength(1)
{
}

Coord Snake::getHeadPosition()
{
	return mHeadPos;
}

Coord Snake::getTailPosition()
{
	return mBodyPos.front();
}

int Snake::getHeadDirection()
{
	return mHeading;
}

int Snake::getLength()
{
	return mLength;
}

void Snake::move(GameBoard& table, int& colliedObj)
{
	Coord collCheck = mHeadPos;
	collCheck.goOneSpace(mHeading);
	int collObj = table.getTile(collCheck.getX(), collCheck.getY());
	colliedObj = collObj;
	if (collObj == BODY || collObj == WALL)
	{
		return;
	}
	else if (collObj == APPLE)
	{
		mBodyPos.push(mHeadPos);
		table.setTile(mHeadPos.getX(), mHeadPos.getY(), BODY);
		mLength++;
		table.placeApple();
	}
	else
	{
		if (mLength > 1)
		{
			table.setTile(mHeadPos.getX(), mHeadPos.getY(), BODY);
			mBodyPos.push(mHeadPos);
			table.setTile(mBodyPos.front().getX(), mBodyPos.front().getY(), FLOOR);
			mBodyPos.pop();
		}
		else
		{
			table.setTile(mHeadPos.getX(), mHeadPos.getY(), FLOOR);
		}
	}
	mHeadPos.goOneSpace(mHeading);
	table.setTile(mHeadPos.getX(), mHeadPos.getY(), HEAD);
}

void Snake::rotate(int direction)
{
	mHeading = direction;
}