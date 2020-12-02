#ifndef SNAKE_H
#define SNAKE_H

class Snake
{
private:
	sf::RenderWindow * window;
	sf::RectangleShape rect;
	std::vector<sf::RectangleShape> snake;

	int width, height;
	int size;
	int len;

	int x, y, tempX, tempY;
	int vx, vy;
	
	sf::Vector2f lastPos;

private:
	void checkCollision();

public:
	Snake();
	Snake(sf::RenderWindow * wnd, int w, int h);
	virtual ~Snake();

	void update();
	void render();

	void setDir(int dx, int dy);
	bool eat(sf::Vector2i pos_);
	std::vector<sf::RectangleShape> getSnake();
	bool collision(std::vector<sf::RectangleShape> walls);
	sf::Vector2f lastPosition();
};

#endif // !SNAKE_H