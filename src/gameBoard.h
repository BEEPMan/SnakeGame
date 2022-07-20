#pragma once

#include<string.h>
#include<iostream>
#include"coord.h"

#define WALL -1
#define FLOOR 0
#define HEAD 1
#define BODY 2
#define APPLE 3

// WALL = "��", FLOOR = "��", HEAD = "��", BODY = "��", APPLE = "��"
// WALL = "\u25A0", FLOOR = "\u25A1", HEAD = "\u25CF", BODY = "\u25C6", APPLE = "\u2605"

class GameBoard
{
public:
	GameBoard();
	GameBoard(int size);
	~GameBoard();
	int getTile(int x, int y);
	void setTile(int x, int y, int objNum);
	void placeApple();
	void initGameBoard();
	void printGameBoard();
private:
	int mSize;
	int** mTable;
};