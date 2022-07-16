#include<iostream>
#include<time.h>
#include<stdlib.h>
#include<Windows.h>
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
// WALL = "\u25A0", FLOOR = "\u25A1", HEAD = "\u25CF", BODY = "\u25CB", APPLE = "\u2605"

using namespace std;

static int map[SIZE][SIZE] = { 0 };

class coord
{
public:
	coord(){}
	coord(int initY, int initX)
		: y(initY), x(initX)
	{

	}
	int getY()
	{
		return y;
	}
	int getX()
	{
		return x;
	}
	void setY(int dest)
	{
		y = dest;
	}
	void setX(int dest)
	{
		x = dest;
	}
	void goOneSpace(int direction)
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
private:
	int y, x;
};

class snake
{
public:
	snake()
		: headPos(START_POS_Y, START_POS_X), heading(0), length(1)
	{

	}
	coord getHeadPosition()
	{
		return headPos;
	}
	int getHeadDirection()
	{
		return heading;
	}
	void move(bool isEat)
	{
		if (length > 1)
		{
			if (isEat)
			{
				tailPos[length].setY(headPos.getY());
				tailPos[length].setX(headPos.getX());
				map[tailPos[length].getY()][tailPos[length].getX()] = BODY;
				length++;
			}
			else
			{
				map[tailPos[1].getY()][tailPos[1].getX()] = FLOOR;
				for (int i = 1; i < length - 1; i++)
				{
					tailPos[i].setY(tailPos[i + 1].getY());
					tailPos[i].setX(tailPos[i + 1].getX());
				}
				tailPos[length - 1].setY(headPos.getY());
				tailPos[length - 1].setX(headPos.getX());
				map[tailPos[length - 1].getY()][tailPos[length - 1].getX()] = BODY;
			}
			
		}
		else
		{
			if (isEat)
			{
				map[headPos.getY()][headPos.getX()] = BODY;
				tailPos[length].setX(headPos.getY());
				tailPos[length].setY(headPos.getX());
				length++;
			}
			else
				map[headPos.getY()][headPos.getX()] = FLOOR;
		}
		headPos.goOneSpace(heading);

		map[headPos.getY()][headPos.getX()] = HEAD;
	}
	void Rotate(int direction)
	{
		heading = direction;
	}
private:
	coord headPos;
	int heading;
	coord tailPos[SIZE * SIZE + 3];
	int length;
};

static snake player;

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
	map[snakePos->getY()][snakePos->getX()] = HEAD;
	delete snakePos;
	coord* applePos = new coord((int)rand() % (SIZE - 2) + 1, (int)rand() % (SIZE - 2) + 1);
	map[applePos->getY()][applePos->getX()] = APPLE;
	delete applePos;
	return;
}

void Update(bool* isGameOver)
{
	coord* snakePos = new coord(player.getHeadPosition());
	snakePos->goOneSpace(player.getHeadDirection());
	if (map[snakePos->getY()][snakePos->getX()] == WALL || map[snakePos->getY()][snakePos->getX()] == BODY)
	{
		(*isGameOver) = true;
		return;
	}
	if (map[snakePos->getY()][snakePos->getX()] == APPLE)
	{
		player.move(true);
		coord* applePos = new coord((int)rand() % (SIZE - 2) + 1, (int)rand() % (SIZE - 2) + 1);
		map[applePos->getY()][applePos->getX()] = APPLE;
		delete applePos;
	}
	else
	{
		player.move(false);
	}
	delete snakePos;
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
				cout << "\u25CB";
			}
			else if (map[i][j] == APPLE)
			{
				cout << "\u2605";
			}
		}
		cout << endl;
	}
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
			if (curTime - oldTime > 500)
				break;
		}
	}
	Release();
	return 0;
}
