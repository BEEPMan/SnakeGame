#include<iostream>
#include<time.h>
#include<stdlib.h>
#include<Windows.h>
#include"coord.h"
#include"Snake.h"
#include"gameBoard.h"

#define SIZE 16
#define START_POS_Y 3
#define START_POS_X 3

using namespace std;

void Init(GameBoard& table, Snake& player)
{
	table.initGameBoard();
	Coord* SnakePos = new Coord(player.getHeadPosition());
	table.setTile(SnakePos->getX(), SnakePos->getY(), HEAD);
	delete SnakePos;
	table.placeApple();
	return;
}

void Update(GameBoard& table, Snake& player, int& tick, bool& isGameOver)
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

void Render(GameBoard& table, Snake& player)
{
	system("cls");

	table.printGameBoard();
	cout << endl << "SCORE: " << player.getLength() << endl;
	return;
}

void Release(GameBoard& table, Snake& player)
{
	return;
}

int main()
{
	GameBoard table(SIZE);
	Snake player(Coord(START_POS_X,START_POS_Y),SIZE*SIZE);
	bool isGameOver = false;
	int tick = 500;
	clock_t curTime, oldTime;
	srand(time(NULL));
	Init(table, player);

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
		Update(table, player, tick, isGameOver);
		if (isGameOver)
		{
			system("cls");
			cout << "GameOver" << endl;
			break;
		}
		Render(table, player);
		while (1)
		{
			curTime = clock();
			if (curTime - oldTime > tick)
				break;
		}
	}
	Release(table, player);
	return 0;
}
