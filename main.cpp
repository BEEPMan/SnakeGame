#include<iostream>
#include<time.h>
#include<Windows.h>
#define SIZE 16
#define WALL -1
#define FLOOR 0
#define HEAD 1
#define BODY 2
#define APPLE 3
#define START_POS_X 3
#define START_POS_Y 3

// WALL = "¡á", FLOOR = "¡à", HEAD = "¡Ü", BODY = "¡Û", APPLE = "¡Ú"
// WALL = "\u25A0", FLOOR = "\u25A1", HEAD = "\u25CF", BODY = "\u25CB", APPLE = "\u2605"

using namespace std;

class snake
{
	int headX, headY;
	int tailX, tailY;
	int headingX, headingY;
	int length;
};

void Init(int (*map)[SIZE])
{
	for (int i = 0; i < SIZE; i++)
	{
		map[i][0] = WALL;
		map[0][i] = WALL;
		map[i][SIZE - 1] = WALL;
		map[SIZE - 1][i] = WALL;
	}
	map[START_POS_X][START_POS_Y] = HEAD;
}

void Update(int(*map)[SIZE], int* curPosX, int* curPosY, int x, int y, bool* isGameOver)
{
	map[(*curPosY)][(*curPosX)] = FLOOR;
	int* heading = &(map[(*curPosY) - y][(*curPosX) + x]);
	if ((*heading) == WALL || (*heading) == BODY)
	{
		(*isGameOver) = true;
		return;
	}
	(*heading) = HEAD;
	(*curPosX) += x;
	(*curPosY) -= y;
	return;
}

void Render(int(*map)[SIZE])
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
}

void Release()
{

}

int main()
{
	int map[SIZE][SIZE] = { 0 }, x = 0, y = 0;
	int curPosX = START_POS_X, curPosY = START_POS_Y;
	bool isGameOver = false;
	clock_t curTime, oldTime;
	Init(map);

	while (1)
	{
		if (GetAsyncKeyState('Q') & 0x0001)
			break;
		else if (GetAsyncKeyState(VK_LEFT) & 0x0001)
		{
			x = -1;
			y = 0;
		}
		else if (GetAsyncKeyState(VK_RIGHT) & 0x0001)
		{
			x = 1;
			y = 0;
		}
		else if (GetAsyncKeyState(VK_UP) & 0x0001)
		{
			x = 0;
			y = 1;
		}
		else if (GetAsyncKeyState(VK_DOWN) & 0x0001)
		{
			x = 0;
			y = -1;
		}
		oldTime = clock();
		Update(map, &curPosX, &curPosY, x, y, &isGameOver);
		if (isGameOver)
		{
			system("cls");
			cout << "GameOver" << endl;
			break;
		}
		Render(map);
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