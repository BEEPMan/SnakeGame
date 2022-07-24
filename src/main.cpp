#include<time.h>
#include<stdlib.h>
#include<Windows.h>

#include<iostream>
#include<string>

#include"vector2d.h"
#include"snake.h"
#include"gameboard.h"
#include"screen.h"

#define SIZE 16
#define START_POS_Y 3
#define START_POS_X 3

using namespace std;

void Init(GameBoard& table, Snake& player)
{
	table.InitGameBoard();
	table.set_tile(player.head_position().x(), player.head_position().y(), HEAD);
	table.PlaceApple();
	return;
}

void Update(GameBoard& table, Snake& player, int& tick, bool& is_game_over)
{
	player.Move(table);
	switch (player.collided_object())
	{
	case WALL:
		is_game_over = true;
		return;
	case BODY:
		is_game_over = true;
		return;
	case APPLE:
		if (player.length() % 5 == 0 && tick > 100)
			tick -= 100;
		return;
	default:
		return;
	}
	return;
}

void Render(GameBoard& table, Snake& player, string text_buffer)
{
	ClearScreen();

	table.PrintGameBoard();
	text_buffer = "Score: " + to_string(player.length());
	PrintScreen(0, SIZE + 1, text_buffer);

	FlipScreen();
	return;
}

void Release(GameBoard& table, Snake& player)
{
	return;
}

int main()
{
	GameBoard table(SIZE);
	Snake player(Vector2D(START_POS_X,START_POS_Y),SIZE*SIZE);
	bool is_game_over = false;
	int tick = 500;
	clock_t current_time, old_time;
	string text_buffer;
	srand(time(NULL));
	InitScreen();
	Init(table, player);

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
		Update(table, player, tick, is_game_over);
		if (is_game_over)
		{
			break;
		}
		Render(table, player, text_buffer);
		old_time = clock();
		while (1)
		{
			current_time = clock();
			if (current_time - old_time > tick)
				break;
		}
	}
	Release(table, player);
	ReleaseScreen();

	system("cls");
	cout << "GAME OVER" << endl;
	return 0;
}
