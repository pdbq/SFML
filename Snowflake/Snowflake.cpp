#include "stdafx.h"
#include "Snowflake.h"


float Snowflake::dist(float x1, float y1, float x2, float y2)
{
	float d = sqrt(powf(x2 - x1, 2) + powf(y2 - y1, 2));
	return d;
}

Snowflake::Snowflake()
{
}

Snowflake::Snowflake(sf::RenderWindow * wnd, int width, int height)
	:window(wnd), width(width), height(height)
{
	this->r = 2.f;
	this->circle.setRadius(this->r);

	this->x = this->width;
	this->y = this->height / 2;
}


Snowflake::~Snowflake()
{
}

void Snowflake::update()
{
	this->x -= 1;
	this->y += (rand() % 5) - 2;

	float t = abs(cos(45) * (this->x - this->width / 2));

	if (this->y > this->width / 2)
		this->y = this->width / 2;
	else if (this->y < this->width / 2 - t)
		this->y = this->width / 2 - t;

	this->circle.setPosition(this->x, this->y);
}

void Snowflake::render(sf::RenderTarget * target)
{
	if (!target)
		target = this->window;

	this->circle.setOrigin(0, 0);
	target->draw(this->circle);

	this->circle.setOrigin(0, y * 2 - height);
	target->draw(this->circle);
}

bool Snowflake::finished()
{
	return (x < this->width / 2);
}

bool Snowflake::intersect(std::vector<Snowflake> s)
{
	bool res = false;
	for (size_t i = 0; i < s.size(); i++)
	{
		float d = this->dist(s[i].getX(), s[i].getY(), this->x, this->y);
		if (d < this->r * 2)
		{
			res = true;
			break;
		}
	}
	return res;
}

int Snowflake::getX()
{
	return this->x;
}

int Snowflake::getY()
{
	return this->y;
}
