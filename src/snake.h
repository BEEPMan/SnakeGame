#pragma once

#include<queue>

#include"vector2d.h"
#include"gameboard.h"

using namespace std;

class Snake
{
public:
	Snake();
	Snake(Vector2D start_position, int max_size);
	Vector2D head_position();
	Vector2D tail_position();
	int head_direction();
	int length();
	int collided_object();
	void Move(GameBoard& table);
	void Rotate(int direction);
private:
	Snake(const Snake&);
	void operator=(const Snake&);
	Vector2D head_position_;
	int head_direction_;
	queue<Vector2D> body_position_;
	int length_;
	Vector2D collide_checker_;
	int collided_object_;
};