#include "stdafx.h"
#include "Fruit.h"


bool Fruit::intersect(sf::Vector2f obj)
{
	if (obj.x == x && obj.y == y)
		return true;
	return false;
}

Fruit::Fruit()
{
}

Fruit::Fruit(sf::RenderWindow * wnd, int w, int h, std::vector<sf::RectangleShape> snake, std::vector<sf::RectangleShape> walls)
	:window(wnd), width(w), height(h)
{
	size = 20;

	bool ok;
	do
	{
		ok = true;

		x = (rand() % width) / size * size;
		y = (rand() % height) / size * size;

		for (size_t i = 0; i < snake.size(); i++)
		{
			if (intersect(snake[i].getPosition()))
			{
				ok = false;
			}
		}

		for (size_t i = 0; i < walls.size(); i++)
		{
			if (intersect(walls[i].getPosition()))
			{
				ok = false;
			}
		}
	} while (!ok);

	rect.setSize(sf::Vector2f(size, size));
	rect.setFillColor(sf::Color::Red);
	rect.setPosition(x, y);
}


Fruit::~Fruit()
{
}

void Fruit::render()
{
	window->draw(rect);
}

sf::Vector2i Fruit::getPos()
{
	return sf::Vector2i(x, y);
}
