#ifndef FRUIT_H
#define FRUIT_H

class Fruit
{
private:
	sf::RenderWindow * window;
	sf::RectangleShape rect;

	int width, height;
	int x, y;
	int size;

private:
	bool intersect(sf::Vector2f obj);

public:
	Fruit();
	Fruit(sf::RenderWindow * wnd, int w, int h, std::vector<sf::RectangleShape> snake, std::vector<sf::RectangleShape> walls);
	virtual ~Fruit();

	void render();

	sf::Vector2i getPos();
};

#endif // !FRUIT_H