#include<iostream>
#define SIZE 16
#define WALL -1
#define FLOOR 0
#define HEAD 1
#define TAIL 2
#define APPLE 3

// WALL = "¡á", FLOOR = "¡à", HEAD = "¡Ü", TAIL = "¡Û", APPLE = "¡Ú"
// WALL = "\u25A0", FLOOR = "\u25A1", HEAD = "\u25CF", TAIL = "\u25CB", APPLE = "\u2605"

using namespace std;

int main()
{
	int map[SIZE][SIZE] = { 0 };

	for (int i = 0; i < SIZE; i++)
	{
		map[i][0] = WALL;
		map[0][i] = WALL;
		map[i][SIZE - 1] = WALL;
		map[SIZE - 1][i] = WALL;
	}

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
			else if (map[i][j] == TAIL)
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