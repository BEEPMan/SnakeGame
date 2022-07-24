#pragma once

#include<string.h>

#include<iostream>
#include<vector>

#include"vector2d.h"
#include"screen.h"

#define WALL -1
#define FLOOR 0
#define HEAD 1
#define BODY 2
#define APPLE 3

// WALL = "¡á", FLOOR = "¡à", HEAD = "¡Ü", BODY = "¡Û", APPLE = "¡Ú"
// WALL = "\u25A0", FLOOR = "\u25A1", HEAD = "\u25CF", BODY = "\u25C6", APPLE = "\u2605"

using namespace std;

class GameBoard
{
public:
	GameBoard();
	GameBoard(int size);
	int tile(int x, int y);
	void set_tile(int x, int y, int object_number);
	void PlaceApple();
	void InitGameBoard();
	void PrintGameBoard();
private:
	GameBoard(const GameBoard&);
	void operator=(const GameBoard&);
	int size_;
	vector<vector<int>> table_;
};