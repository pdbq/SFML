#ifndef BARNSLEYFERN_H
#define BARNSLEYFERN_H

class Barnsleyfern
{
private:
	sf::RenderWindow * window;
	int width, height;

	sf::CircleShape circle;
	float x, y;

private:
	void NextStep();

public:
	Barnsleyfern();
	Barnsleyfern(sf::RenderWindow * window, int width, int height);
	virtual ~Barnsleyfern();

	void update();
	void render(sf::RenderTarget * target = NULL);
};

#endif // !BARNSLEYFERN_H