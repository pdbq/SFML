#include "stdafx.h"
#include "Snake.h"


void Snake::checkCollision()
{
	for (size_t j = 0; j < snake.size() - 1; j++)
	{
		snake[j].setPosition(snake[j + 1].getPosition());
	}

	snake.pop_back();
	len--;
	x = tempX;
	y = tempY;
}

Snake::Snake()
{
}

Snake::Snake(sf::RenderWindow * wnd, int w, int h)
	:window(wnd), width(w), height(h)
{
	size = 20;
	x = 0;
	y = 0;
	vx = 0;
	vy = 0;
	len = 30;

	rect.setSize(sf::Vector2f(size, size));

	for (size_t i = 0; i < len; i++)
	{
		snake.push_back(rect);
	}
}


Snake::~Snake()
{
}

void Snake::update()
{
	tempX = x;
	tempY = y;
	x += vx;
	y += vy;

	lastPos = snake[snake.size() - 1].getPosition();
	rect.setPosition(lastPos);

	for (size_t i = snake.size() - 1; i > 0 ; i--)
	{
		snake[i].setPosition(snake[i - 1].getPosition());
	}
	snake[0].setPosition(x*size, y*size);
}

void Snake::render()
{
	for (size_t i = 0; i < snake.size(); i++)
	{
		window->draw(snake[i]);

	}
}

void Snake::setDir(int dx, int dy)
{
	if (vx != -dx)
		vx = dx;
	if (vy != -dy)
		vy = dy;
}

bool Snake::eat(sf::Vector2i pos_)
{
	if (snake[0].getPosition().x == pos_.x && snake[0].getPosition().y == pos_.y)
	{
		len++;
		snake.push_back(rect);
		return true;
	}
	return false;
}

std::vector<sf::RectangleShape> Snake::getSnake()
{
	return snake;
}

bool Snake::collision(std::vector<sf::RectangleShape> walls)
{
	for (size_t i = 0; i < walls.size(); i++)
	{
		if (snake[0].getPosition().x == walls[i].getPosition().x && snake[0].getPosition().y == walls[i].getPosition().y)
		{
			checkCollision();
			return true;
		}
	}
	if (snake[0].getPosition().x < 0 || snake[0].getPosition().x > width - size || snake[0].getPosition().y < 0 || snake[0].getPosition().y > height - size)
	{
		checkCollision();
		return true;
	}

	for (size_t i = 1; i < snake.size(); i++)
	{
		if (snake[0].getPosition().x == snake[i].getPosition().x && snake[0].getPosition().y == snake[i].getPosition().y)
		{
			checkCollision();
			return true;
		}
	}
	return false;
}

sf::Vector2f Snake::lastPosition()
{
	return lastPos;
}
