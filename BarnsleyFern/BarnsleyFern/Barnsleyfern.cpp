#include "stdafx.h"
#include "Barnsleyfern.h"


void Barnsleyfern::NextStep()
{
	float nextX, nextY;
	float r = rand() % 100;
	r = r / 100;
	
	if (r < 0.01)
	{
		nextX = 0;
		nextY = 0.16 * y;
	}
	else if (r < 0.86)
	{
		nextX = 0.85 * x + 0.04 * y;
		nextY = -0.04 * x + 0.85 * y + 1.6;
	}
	else if (r < 0.93)
	{
		nextX = 0.2 * x - 0.26 * y;
		nextY = 0.23 * x + 0.22 * y + 1.6;
	}
	else
	{
		nextX = -0.15 * x + 0.28 * y;
		nextY = 0.26 * x + 0.24 * y + 0.44;
	}

	float pX = this->width * (x + 3) / 6;
	float pY = this->height - this->height * ((y + 2) / 14);

	this->circle.setPosition(pX, pY);

	this->x = nextX;
	this->y = nextY;
}

Barnsleyfern::Barnsleyfern()
{
}

Barnsleyfern::Barnsleyfern(sf::RenderWindow * window, int width, int height)
	:window(window), width(width), height(height)
{
	this->circle.setRadius(1.f);
	this->circle.setFillColor(sf::Color::Green);

	this->x = 0.f;
	this->y = 0.f;
}


Barnsleyfern::~Barnsleyfern()
{
}

void Barnsleyfern::update()
{
	this->NextStep();
	this->render();
}

void Barnsleyfern::render(sf::RenderTarget * target)
{
	if (!target)
		target = this->window;

	target->draw(this->circle);
}
