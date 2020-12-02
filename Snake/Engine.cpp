#include "stdafx.h"
#include "Engine.h"


void Engine::initWindow()
{
	width = 600;
	height = 600;

	window = new sf::RenderWindow(sf::VideoMode(width, height), "Snake game");

	window->setFramerateLimit(10);
	window->setVerticalSyncEnabled(false);
}

void Engine::initSnake()
{
	snake = Snake(window, width, height);
}

void Engine::initFruit()
{
	fruit = Fruit(window, width, height, snake.getSnake(), wall.getWalls());
}

void Engine::initWall()
{
	wall = Wall(window);
}

Engine::Engine()
{
	initWindow();
	initSnake();
	initWall();
	initFruit();
}


Engine::~Engine()
{
	delete window;
}

void Engine::updateSFMLEvent()
{
	while (window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window->close();
	}
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		snake.setDir(-1, 0);
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		snake.setDir(1, 0);
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		snake.setDir(0, 1);
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		snake.setDir(0, -1);
	
}

void Engine::update()
{
	updateSFMLEvent();
	snake.update();
	if (snake.eat(fruit.getPos()))
	{
		initFruit();
	}
	if (snake.collision(wall.getWalls()))
	{
		wall.addWall(snake.lastPosition());
	}
}

void Engine::render()
{
	window->clear();
	snake.render();
	fruit.render();
	wall.render();
	window->display();
}

void Engine::run()
{
	while (window->isOpen())
	{
		update();
		render();
	}
}
