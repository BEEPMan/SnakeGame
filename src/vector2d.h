#pragma once

#define LEFT 11
#define RIGHT 12
#define UP 13
#define DOWN 14

class Vector2D
{
public:
	Vector2D();
	Vector2D(int x, int y);
	Vector2D(const Vector2D& other);
	void operator=(const Vector2D& other);
	int x();
	int y();
	void set_x(int x);
	void set_y(int y);
	void GoOneSpace(int direction);
private:
	int x_;
	int y_;
};