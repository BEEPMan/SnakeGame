#pragma once

#include<string.h>
#include<iostream>
#include"coord.h"

#define WALL -1
#define FLOOR 0
#define HEAD 1
#define BODY 2
#define APPLE 3

// WALL = "¡á", FLOOR = "¡à", HEAD = "¡Ü", BODY = "¡Û", APPLE = "¡Ú"
// WALL = "\u25A0", FLOOR = "\u25A1", HEAD = "\u25CF", BODY = "\u25C6", APPLE = "\u2605"

class map
{
public:
	map(int size);
	~map();
	int getTile(int x, int y);
	void setTile(int x, int y, int objNum);
	void placeApple();
	void initMap();
	void printMap();
private:
	int mSize;
	int** mTable;
};