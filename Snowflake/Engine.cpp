#include "stdafx.h"
#include "Engine.h"


void Engine::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(this->width, this->height), "Snowflake generator");
	this->window->setFramerateLimit(60);
	this->window->setVerticalSyncEnabled(false);

	this->view = sf::View(sf::FloatRect(0, 0, this->width, this->height));
}

void Engine::initSnowflake()
{
	this->snowflake = Snowflake(this->window, this->width, this->height);
}

Engine::Engine()
{
}

Engine::Engine(int width, int height)
	:width(width), height(height)
{
	this->initWindow();
	this->initSnowflake();
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

	while (!this->snowflake.finished() && !this->snowflake.intersect(this->snowflakes))
	{
		this->snowflake.update();
	}

	this->snowflakes.push_back(this->snowflake);
	this->initSnowflake();
}

void Engine::render()
{
	this->window->clear();

	for (size_t t = 0; t < 6; t++)
	{
		this->view.rotate(60);
		this->window->setView(this->view);

		this->snowflake.render();

		for (size_t i = 0; i < this->snowflakes.size(); i++)
		{
			this->snowflakes[i].render();
		}
	}

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
