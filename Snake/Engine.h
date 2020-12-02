#ifndef ENGINE_H
#define ENGINE_H

#include "Snake.h"
#include "Fruit.h"
#include "Wall.h"

class Engine
{
private:
	sf::RenderWindow * window;
	sf::Event event;
	
	int width, height;

	Snake snake;
	Fruit fruit;
	Wall wall;

private:
	void initWindow();
	void initSnake();
	void initFruit();
	void initWall();

public:
	Engine();
	virtual ~Engine();

	void updateSFMLEvent();
	void update();
	void render();
	void run();
};

#endif // !ENGINE_H