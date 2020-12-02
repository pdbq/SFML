#ifndef WALL_H
#define WALL_H

class Wall
{
private:
	sf::RenderWindow * window;
	sf::RectangleShape rect;

	std::vector<sf::RectangleShape> walls;

public:
	Wall();
	Wall(sf::RenderWindow * window);
	virtual ~Wall();

	void render();

	void addWall(sf::Vector2f pos);
	std::vector<sf::RectangleShape> getWalls();
};

#endif // !WALL_H
