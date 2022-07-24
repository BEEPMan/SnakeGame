#include"gameboard.h"

GameBoard::GameBoard() {}

GameBoard::GameBoard(int size)
	: size_(size)
{
	table_ = vector<vector<int>>(size, vector<int>(size, 0));
}

int GameBoard::tile(int x, int y)
{
	return table_[x][y];
}

void GameBoard::set_tile(int x, int y, int object_number)
{
	table_[x][y] = object_number;
}

void GameBoard::PlaceApple()
{
	Vector2D apple_position((int)rand() % (size_ - 2) + 1, (int)rand() % (size_ - 2) + 1);
	while (table_[apple_position.x()][apple_position.y()] != FLOOR)
	{
		apple_position.set_x((int)rand() % (size_ - 2) + 1);
		apple_position.set_y((int)rand() % (size_ - 2) + 1);
	}
	table_[apple_position.x()][apple_position.y()] = APPLE;
}

void GameBoard::InitGameBoard()
{
	for (int i = 0; i < size_; i++)
	{
		table_[i][0] = WALL;
		table_[0][i] = WALL;
		table_[i][size_ - 1] = WALL;
		table_[size_ - 1][i] = WALL;
	}
}

void GameBoard::PrintGameBoard()
{
	for (int i = 0; i < size_; i++)
	{
		for (int j = 0; j < size_; j++)
		{
			if (table_[i][j] == WALL)
			{
				PrintScreen(j * 2, i, const_cast<char *>("\u25A0"));
			}
			else if (table_[i][j] == FLOOR)
			{
				PrintScreen(j * 2, i, const_cast<char*>("\u25A1"));
			}
			else if (table_[i][j] == HEAD)
			{
				PrintScreen(j * 2, i, const_cast<char*>("\u25CF"));
			}
			else if (table_[i][j] == BODY)
			{
				PrintScreen(j * 2, i, const_cast<char*>("\u25C6"));
			}
			else if (table_[i][j] == APPLE)
			{
				PrintScreen(j * 2, i, const_cast<char*>("\u2605"));
			}
		}
	}
}