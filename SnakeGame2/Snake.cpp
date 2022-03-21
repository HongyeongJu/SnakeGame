#include "Snake.h"

Snake::Snake(int** map, int mapsize)
{
	this->map = map;
	this->mapsize = mapsize;
	x = 0;
	y = 0;
	direction = Direction::LEFT;
}

void Snake::move()
{
	// �����̱����� �� ��ġ�� ������Ų��.
	improveTail();
	if (direction == Direction::LEFT) {
		if (x == 0) {
			x = mapsize - 1;
		}
		else {
			x--;
		}
	}
	else if (direction == Direction::RIGHT) {
		if (x == mapsize - 1) {
			x = 0;
		}
		else {
			x++;
		}
	}
	else if (direction == Direction::UP) {
		if (y == 0) {
			y = mapsize - 1;
		}
		else {
			y--;
		}
	}
	else if (direction == Direction::DOWN) {
		if (y == mapsize - 1) {
			y = 0;
		}
		else {
			y++;
		}
	}
}

// �̰� ���� ��������� �Ȼ�� �������� �߸𸣰��� .. Ȯ���� �ʿ��� 
void Snake::cutTail()
{
	tails.pop_front();
	/*
	if (tails.size() != tailSize) {
		tails.pop_front();
	}
	*/
}

// ���� ���� �Լ�
void Snake::improveTail() {
	tails.push_back(std::make_pair(x, y));
}

void Snake::setPosition(int x, int y)
{
	this->x = x;
	this->y = y;
	map[y][x] = Object::HEAD;
}

void Snake::setDirection(int direction)
{
	if (tails.size() == 0) {
		this->direction = direction;
	}
	else {
		if (this->direction == Direction::LEFT && direction == Direction::RIGHT) {

		}
		else if (this->direction == Direction::RIGHT && direction == Direction::LEFT) {

		}
		else if (this->direction == Direction::UP && direction == Direction::DOWN) {

		}
		else if (this->direction == Direction::DOWN && direction == Direction::UP) {

		}
		else {
			this->direction = direction;
		}
	}
	
}


int Snake::getX() {
	return x;
}

int Snake::getY() {
	return y;
}