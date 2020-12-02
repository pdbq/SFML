#include "stdafx.h"
#include "Engine.h"


void Engine::initWindow()
{
	this->width = 700;
	this->height = 700;

	this->window = new sf::RenderWindow(sf::VideoMode(this->width, this->height), "Barnsley fern");
	this->window->setFramerateLimit(60);
	this->window->setVerticalSyncEnabled(false);
}

void Engine::initBarnsleyfern()
{
	this->barnsleyfern = Barnsleyfern(this->window, this->width, this->height);
}

Engine::Engine()
{
	this->initWindow();
	this->initBarnsleyfern();
}


Engine::~Engine()
{
	delete this->window;
}

void Engine::updateSFMLEvent()
{
	while (this->window->pollEvent(this->event))
	{
		if (this->event.type == sf::Event::Closed)
			this->window->close();
	}
}

void Engine::update()
{
	this->updateSFMLEvent();
	for (size_t i = 0; i < 100; i++)
	{
		this->barnsleyfern.update();
	}
}

void Engine::render()
{
	//this->window->clear();
	//this->barnsleyfern.render();
	this->window->display();
}

void Engine::run()
{
	while (this->window->isOpen())
	{
		this->update();
		this->render();
	}
}
