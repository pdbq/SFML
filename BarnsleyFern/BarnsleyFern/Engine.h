#ifndef ENGINE_H
#define ENGINE_H

#include "Barnsleyfern.h"

class Engine
{
private:
	sf::RenderWindow * window;
	sf::Event event;
	int width, height;

	Barnsleyfern barnsleyfern;
private:
	void initWindow();
	void initBarnsleyfern();

public:
	Engine();
	virtual ~Engine();

	void updateSFMLEvent();
	void update();
	void render();
	void run();
};

#endif // !ENGINE_H