#include"snake.h"

Snake::Snake()
	: head_position_(1, 1), head_direction_(0), length_(1)
{
}

Snake::Snake(Vector2D startPos, int maxSize)
	: head_position_(startPos.x(), startPos.y()), head_direction_(0), length_(1)
{
}

Vector2D Snake::head_position()
{
	return head_position_;
}

Vector2D Snake::tail_position()
{
	return body_position_.front();
}

int Snake::head_direction()
{
	return head_direction_;
}

int Snake::length()
{
	return length_;
}

int Snake::collided_object()
{
	return collided_object_;
}

void Snake::Move(GameBoard& table)
{
	collide_checker_ = head_position_;
	collide_checker_.GoOneSpace(head_direction_);
	collided_object_ = table.tile(collide_checker_.x(), collide_checker_.y());
	if (collided_object_ == BODY || collided_object_ == WALL)
	{
		return;
	}
	else if (collided_object_ == APPLE)
	{
		body_position_.push(head_position_);
		table.set_tile(head_position_.x(), head_position_.y(), BODY);
		length_++;
		table.PlaceApple();
	}
	else
	{
		if (length_ > 1)
		{
			table.set_tile(head_position_.x(), head_position_.y(), BODY);
			body_position_.push(head_position_);
			table.set_tile(body_position_.front().x(), body_position_.front().y(), FLOOR);
			body_position_.pop();
		}
		else
		{
			table.set_tile(head_position_.x(), head_position_.y(), FLOOR);
		}
	}
	head_position_.GoOneSpace(head_direction_);
	table.set_tile(head_position_.x(), head_position_.y(), HEAD);
}

void Snake::Rotate(int direction)
{
	head_direction_ = direction;
}