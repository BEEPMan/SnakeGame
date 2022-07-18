#include"map.h"

map::map(int size)
	: mSize(size)
{
	mTable = new int* [size];
	for (int i = 0; i < size; i++)
	{
		mTable[i] = new int[size];
		memset(mTable[i], 0, (int)sizeof(int) * size);
	}
}

map::~map()
{
	for (int i = 0; i < mSize; i++)
	{
		delete[] mTable[i];
	}
	delete[] mTable;
}

int map::getTile(int x, int y)
{
	return mTable[x][y];
}

void map::setTile(int x, int y, int objNum)
{
	mTable[x][y] = objNum;
}

void map::placeApple()
{
	coord* applePos = new coord((int)rand() % (mSize - 2) + 1, (int)rand() % (mSize - 2) + 1);
	while (mTable[applePos->getX()][applePos->getY()] != FLOOR)
	{
		applePos = new coord((int)rand() % (mSize - 2) + 1, (int)rand() % (mSize - 2) + 1);
	}
	mTable[applePos->getX()][applePos->getY()] = APPLE;
	delete applePos;
}

void map::initMap()
{
	for (int i = 0; i < mSize; i++)
	{
		mTable[i][0] = WALL;
		mTable[0][i] = WALL;
		mTable[i][mSize - 1] = WALL;
		mTable[mSize - 1][i] = WALL;
	}
}

void map::printMap()
{
	for (int i = 0; i < mSize; i++)
	{
		for (int j = 0; j < mSize; j++)
		{
			if (mTable[i][j] == WALL)
			{
				std::cout << "\u25A0";
			}
			else if (mTable[i][j] == FLOOR)
			{
				std::cout << "\u25A1";
			}
			else if (mTable[i][j] == HEAD)
			{
				std::cout << "\u25CF";
			}
			else if (mTable[i][j] == BODY)
			{
				std::cout << "\u25C6";
			}
			else if (mTable[i][j] == APPLE)
			{
				std::cout << "\u2605";
			}
		}
		std::cout << std::endl;
	}
}