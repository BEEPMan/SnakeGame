#include<iostream>
#include<time.h>
#include<stdlib.h>
#include<Windows.h>
#include"coord.h"
#include"snake.h"

#define SIZE 16
#define START_POS_Y 3
#define START_POS_X 3

#define WALL -1
#define FLOOR 0
#define HEAD 1
#define BODY 2
#define APPLE 3

#define LEFT 11
#define RIGHT 12
#define UP 13
#define DOWN 14

// WALL = "■", FLOOR = "□", HEAD = "●", BODY = "○", APPLE = "★"
// WALL = "\u25A0", FLOOR = "\u25A1", HEAD = "\u25CF", BODY = "\u25C6", APPLE = "\u2605"

using namespace std;

static int map[SIZE][SIZE] = { 0 };
static int tick = 500;

static snake player;

void makeApple()
{
	coord* applePos = new coord((int)rand() % (SIZE - 2) + 1, (int)rand() % (SIZE - 2) + 1);
	while (map[applePos->getX()][applePos->getY()] != FLOOR)
	{
		applePos = new coord((int)rand() % (SIZE - 2) + 1, (int)rand() % (SIZE - 2) + 1);
	}
	map[applePos->getX()][applePos->getY()] = APPLE;
	delete applePos;
}

void Init()
{
	for (int i = 0; i < SIZE; i++)
	{
		map[i][0] = WALL;
		map[0][i] = WALL;
		map[i][SIZE - 1] = WALL;
		map[SIZE - 1][i] = WALL;
	}
	coord* snakePos = new coord(player.getHeadPosition());
	map[snakePos->getX()][snakePos->getY()] = HEAD;
	delete snakePos;
	makeApple();
	return;
}

void Update(bool* isGameOver)
{
	coord* collCheck = new coord(player.getHeadPosition());
	collCheck->goOneSpace(player.getHeadDirection());
	if (map[collCheck->getX()][collCheck->getY()] == WALL || map[collCheck->getX()][collCheck->getY()] == BODY)
	{
		(*isGameOver) = true;
		return;
	}
	if (map[collCheck->getX()][collCheck->getY()] == APPLE)
	{
		map[player.getHeadPosition().getX()][player.getHeadPosition().getY()] = BODY;
		player.move(true);
		makeApple();
		if (player.getLength() % 5 == 0 && tick > 100)
			tick -=  100;
	}
	else
	{
		if (player.getLength() > 1)
		{
			map[player.getHeadPosition().getX()][player.getHeadPosition().getY()] = BODY;
			map[player.getTailPosition().getX()][player.getTailPosition().getY()] = FLOOR;
		}
		else
		{
			map[player.getHeadPosition().getX()][player.getHeadPosition().getY()] = FLOOR;
		}
		player.move(false);
	}
	map[player.getHeadPosition().getX()][player.getHeadPosition().getY()] = HEAD;
	delete collCheck;
	return;
}

void Render()
{
	system("cls");

	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			if (map[i][j] == WALL)
			{
				cout << "\u25A0";
			}
			else if (map[i][j] == FLOOR)
			{
				cout << "\u25A1";
			}
			else if (map[i][j] == HEAD)
			{
				cout << "\u25CF";
			}
			else if (map[i][j] == BODY)
			{
				cout << "\u25C6";
			}
			else if (map[i][j] == APPLE)
			{
				cout << "\u2605";
			}
		}
		cout << endl;
	}
	cout << endl << "SCORE: " << player.getLength() << endl;
	return;
}

void Release()
{
	return;
}

int main()
{
	bool isGameOver = false;
	clock_t curTime, oldTime;
	srand(time(NULL));
	Init();

	while (1)
	{
		if (GetAsyncKeyState('Q') & 0x0001)
			break;
		else if (GetAsyncKeyState(VK_LEFT) & 0x0001)
		{
			player.Rotate(LEFT);
		}
		else if (GetAsyncKeyState(VK_RIGHT) & 0x0001)
		{
			player.Rotate(RIGHT);
		}
		else if (GetAsyncKeyState(VK_UP) & 0x0001)
		{
			player.Rotate(UP);
		}
		else if (GetAsyncKeyState(VK_DOWN) & 0x0001)
		{
			player.Rotate(DOWN);
		}
		oldTime = clock();
		Update(&isGameOver);
		if (isGameOver)
		{
			system("cls");
			cout << "GameOver" << endl;
			break;
		}
		Render();
		while (1)
		{
			curTime = clock();
			if (curTime - oldTime > tick)
				break;
		}
	}
	Release();
	return 0;
}
