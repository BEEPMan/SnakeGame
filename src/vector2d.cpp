#include"vector2d.h"

Vector2D::Vector2D()
	: x_(0), y_(0)
{

}

Vector2D::Vector2D(int x, int y)
	: x_(x), y_(y)
{

}

Vector2D::Vector2D(const Vector2D& other)
	: x_(other.x_), y_(other.y_)
{

}

void Vector2D::operator=(const Vector2D& other)
{
	x_ = other.x_;
	y_ = other.y_;
}

int Vector2D::x()
{
	return x_;
}

int Vector2D::y()
{
	return y_;
}

void Vector2D::set_x(int x)
{
	x_ = x;
}

void Vector2D::set_y(int y)
{
	y_ = y;
}

void Vector2D::GoOneSpace(int direction)
{
	if (direction == LEFT)
	{
		y_ -= 1;
	}
	else if (direction == RIGHT)
	{
		y_ += 1;
	}
	else if (direction == UP)
	{
		x_ -= 1;
	}
	else if (direction == DOWN)
	{
		x_ += 1;
	}
}