#include "stdafx.h"
#include "Wall.h"


Wall::Wall()
{
}

Wall::Wall(sf::RenderWindow * window)
	:window(window)
{
	rect.setSize(sf::Vector2f(20.f, 20.f));
	rect.setFillColor(sf::Color::Blue);
}



Wall::~Wall()
{
}

void Wall::render()
{
	for (size_t i = 0; i < walls.size(); i++)
	{
		window->draw(walls[i]);
	}
}

void Wall::addWall(sf::Vector2f pos)
{
	rect.setPosition(pos);
	walls.push_back(rect);
}

std::vector<sf::RectangleShape> Wall::getWalls()
{
	return walls;
}
