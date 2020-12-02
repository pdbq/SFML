#ifndef ENGINE_H
#define ENGINE_H

#include "Snowflake.h"

class Engine
{
private:
	sf::RenderWindow * window;
	sf::Event event;
	sf::View view;

	int width, height;

	Snowflake snowflake;
	std::vector<Snowflake> snowflakes;

private:
	void initWindow();
	void initSnowflake();

public:
	Engine();
	Engine(int width, int height);
	virtual ~Engine();

	void updateSFMLEvent();
	void update();
	void render();
	void run();
};

#endif // !ENGINE_H