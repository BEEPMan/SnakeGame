#include<iostream>
#include<time.h>
#include<stdlib.h>
#include<Windows.h>
#include"coord.h"
#include"snake.h"
#include"map.h"

#define SIZE 16
#define START_POS_Y 3
#define START_POS_X 3

using namespace std;

static int tick = 500;

static snake player;

void Init(map& table)
{
	table.initMap();
	coord* snakePos = new coord(player.getHeadPosition());
	table.setTile(snakePos->getX(), snakePos->getY(), HEAD);
	delete snakePos;
	table.placeApple();
	return;
}

void Update(map& table, bool& isGameOver)
{
	int colliedObj;
	player.move(table, colliedObj);
	if (colliedObj == WALL || colliedObj == BODY)
	{
		isGameOver = true;
		return;
	}
	else if (colliedObj == APPLE)
	{
		if (player.getLength() % 5 == 0 && tick > 100)
			tick -= 100;
	}
	return;
}

void Render(map& table)
{
	system("cls");

	table.printMap();
	cout << endl << "SCORE: " << player.getLength() << endl;
	return;
}

void Release(map& table)
{
	delete &table;
	return;
}

int main()
{
	map* table = new map(SIZE);
	bool isGameOver = false;
	clock_t curTime, oldTime;
	srand(time(NULL));
	Init(*table);

	while (1)
	{
		if (GetAsyncKeyState('Q') & 0x0001)
			break;
		else if (GetAsyncKeyState(VK_LEFT) & 0x0001)
		{
			player.rotate(LEFT);
		}
		else if (GetAsyncKeyState(VK_RIGHT) & 0x0001)
		{
			player.rotate(RIGHT);
		}
		else if (GetAsyncKeyState(VK_UP) & 0x0001)
		{
			player.rotate(UP);
		}
		else if (GetAsyncKeyState(VK_DOWN) & 0x0001)
		{
			player.rotate(DOWN);
		}
		oldTime = clock();
		Update(*table, isGameOver);
		if (isGameOver)
		{
			system("cls");
			cout << "GameOver" << endl;
			break;
		}
		Render(*table);
		while (1)
		{
			curTime = clock();
			if (curTime - oldTime > tick)
				break;
		}
	}
	Release(*table);
	return 0;
}
